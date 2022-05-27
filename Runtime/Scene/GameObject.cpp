#include "Runtime/Scene/GameObject.h"
#include "Runtime/Base/ScriptObject.h"
#include "Runtime/String/StringUtils.h"
#include "Runtime/Scene/SceneManager.h"
#include "EventDispatcher.h"
#include "Runtime/LuaEngine/LuaEngine.h"
#include "Runtime/Geometry/Intersection.h"
#include "Runtime/Serializer/Audio.serializer.h"

namespace YOSEF{
	GameObject::GameObject() : mComponents(nullptr), mScripts(nullptr){
		mLocalTransform = new(kMemDefaultId)Transform;
		mLocalTransform.mOwner=this;
		mParent = nullptr;
		mLayer = GameObjectLayer_Default;
		mName = "GameObject";
		mbEnable = true;
		mbReceiveRayCast = false;
		mRenderOrder = nullptr;
		mbIsBone = false;
		mbWorldMatrixDirty = true;
		mbLocalMatrixDirty = true;
		mPhysicsComponent = nullptr;
	}
	GameObject::~GameObject(){
		//Info("delete GameObject %s",mName.mText);
		GetEventDispatcher()->RemoveEventListener(this);
		GetEventDispatcher()->RemoveKeyboardListener(this);
		GetEventDispatcher()->RemoveRightButtonEventListener(this);
		GetEventDispatcher()->RemoveMouseMiddleButtonEventListener(this);
		GetEventDispatcher()->RemovePasteEventListener(this);
		GetEventDispatcher()->ReleaseTouchPos(this);
		if (GetEventDispatcher()->mLastGameObjectHovered==this){
			GetEventDispatcher()->mLastGameObjectHovered = nullptr;
		}
		if (GetEventDispatcher()->mLastTouchObject == this) {
			GetEventDispatcher()->mLastTouchObject = nullptr;
		}
		Component*current = mComponents;
		while (current != nullptr){
			Component*prev = current;
			current = current->Next<Component>();
			delete prev;
		}
		ScriptObject*currentScript = mScripts;
		while (currentScript != nullptr) {
			ScriptObject*prevScript = currentScript;
			currentScript = currentScript->Next<ScriptObject>();
			delete prevScript;
		}

		if (mChild != nullptr){
			delete Child<GameObject>();
		}
		if (mRightSibling != nullptr){
			delete RightSibling<GameObject>();
		}
		Clean();
	}
	void GameObject::OnDestroy() {
		ScriptObject*currentScript = mScripts;
		while (currentScript != nullptr) {
			currentScript->OnDestroy();
			currentScript = currentScript->Next<ScriptObject>();
		}
	}

    void GameObject::DumpTree(int nLevel){
        if(nLevel>10){
            return;
        }
        for(int i=0;i<nLevel;++i){
            printf("-");
        }
        printf("%s\n",mName.mText);
        if (mChild != nullptr){
            Child<GameObject>()->DumpTree(nLevel+1);
        }
        if (mRightSibling != nullptr){
            RightSibling<GameObject>()->DumpTree(nLevel);
        }
    }
	const Matrix4x4&GameObject::GetLocalMatrix() {
		if (mbLocalMatrixDirty){
			mLocalTransform.ToMatrix(mLocalMatrix);
			mbLocalMatrixDirty = false;
			mLocalTransform.mbDirty = false;
		}
		return mLocalMatrix;
	}
	const Matrix4x4&GameObject::GetWorldMatrix() {
		if (mbWorldMatrixDirty){
			mbWorldMatrixDirty = false;
			const Matrix4x4&local_matrix = GetLocalMatrix();
			if (mParent != nullptr) {
				GameObject*parent = Parent<GameObject>();
				const Matrix4x4&parent_world_matrix = parent->GetWorldMatrix();
				Matrix4x4MultiplyMatrix4x4(parent_world_matrix.mData, local_matrix.mData, mWorldMatrix.mData);
			}
			else {
				mWorldMatrix = mLocalMatrix;
			}
		}
		return mWorldMatrix;
	}
	void GameObject::MarkWorldMatrixDirty() {
		mbWorldMatrixDirty = true;
		if (mChild != nullptr){
			Child<GameObject>()->MarkWorldMatrixDirty();
		}
		if (mRightSibling != nullptr){
			RightSibling<GameObject>()->MarkWorldMatrixDirty();
		}
	}
	bool GameObject::IsEnabled(){
		return mParent == nullptr ? mbEnable : (mbEnable&&Parent<GameObject>()->IsEnabled());
	}
	void GameObject::RenderMyselfOnly(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	)
	{
		if (mbEnable)
		{
			Component*current = mComponents;
			while (current != nullptr)
			{
				current->Render(rq
#if YOSEF_EDITOR
					, rs
#endif
				);
				current = current->Next<Component>();
			}
		}
	}

	void GameObject::UpdateTransformRecursively(){
		if (mbLocalMatrixDirty || mbWorldMatrixDirty){
			Component*current = mComponents;
			while (current != nullptr){
				current->mbPositionChanged = true;
				current = current->Next<Component>();
			}
		}
		if (mChild != nullptr){
			Child<GameObject>()->UpdateTransformRecursively();
		}
		if (mRightSibling!=nullptr){
			RightSibling<GameObject>()->UpdateTransformRecursively();
		}
	}

	void GameObject::UpdateScriptsRecursively(float deltaTime){
		GameObject*right_sibling = RightSibling<GameObject>();
		if (mObjectMask != -2) {
			if (mbEnable) {
				ScriptObject*current = mScripts;
				while (current != nullptr) {
					ScriptObject*next = current->Next<ScriptObject>();
					if (current->mbEnable)current->Update(deltaTime);
					current = next;
				}
				if (mChild != nullptr) {
					Child<GameObject>()->UpdateScriptsRecursively(deltaTime);
				}
			}
		}
		else {
			DestroyGameObject(this);
		}
		if (right_sibling != nullptr){
			right_sibling->UpdateScriptsRecursively(deltaTime);
		}
	}

	void GameObject::UpdateComponentRecusively(float deltaTime)
	{
		if (mbEnable){//if game object is enabled 
			Component*current = mComponents;
			while (current != nullptr){
				Component * next = current->Next<Component>();
				if(current->mbEnable) current->Update(deltaTime);//if component is enabled
				current = next;
			}
			if (mChild != nullptr){
				Child<GameObject>()->UpdateComponentRecusively(deltaTime);
			}
		}
		if (mRightSibling != nullptr){
			RightSibling<GameObject>()->UpdateComponentRecusively(deltaTime);
		}
	}

	bool GameObject::NewGameObject()
	{
		return true;
	}

	bool GameObject::NewGameObjectWithPrefabName(const char*prefabName)
	{
		lua_State*L = LuaEngine::s_GlobalStatePtr;
		bool ret = false;
		const char*guid = Resource::GetResourceGUIDViaUserName(prefabName);
		if (guid != nullptr)
		{
			PrefabResource*prefab = Resource::LoadResource<PrefabResource>(guid);
			if (prefab != nullptr)
			{
				ret = NewGameObjectWithPrefab(prefab);
			}
			else
			{
				lua_pushnil(L);
			}
		}
		else
		{
			lua_pushnil(L);
		}
		return ret;
	}

	bool GameObject::NewGameObjectWithPrefab(PrefabResource*prefab){
		return false;
	}

	bool GameObject::DestroyGameObject(GameObject*go)
	{
		go->Clean();
		delete go;
		return true;
	}

	void GameObject::AddComponent(Component*component) {
		if (component != nullptr){
			if (mComponents != nullptr){
				mComponents->Append(component);
			}else{
				mComponents = component;
			}
		}
	}

	void GameObject::OnRemoveComponent(Component*component){
	}

	bool GameObject::RemoveComponent(Component*component)
	{
		Component*current = mComponents;
		while (current!=nullptr)
		{
			if (current == component)
			{
				//remove it
				if (current == mComponents)
				{
					Component*next = current->Next<Component>();
					current->LeaveList();
					//last component
					mComponents = next;
				}
				else
				{
					current->LeaveList();
				}
				OnRemoveComponent(component);
				return true;
			}
			current = current->Next<Component>();
		}
		return false;
	}

	Component*GameObject::GetComponent(int classID)
	{
		Component*current = mComponents;
		while (current != nullptr)
		{
			if (current->GetClassID() == classID)
			{
				return current;
			}
			current = current->Next<Component>();
		}
		return nullptr;
	}

	GameObject*GameObject::FindChild(const char*childName){
		GameObject*ret = nullptr;
		if (mName==childName){
			return this;
		}
		if (mChild!=nullptr){
			ret = ((GameObject*)mChild)->FindChild(childName);
			if (ret!=nullptr){
				return ret;
			}
		}
		if (mRightSibling!=nullptr){
			ret = ((GameObject*)mRightSibling)->FindChild(childName);
		}
		return ret;
	}
	void GameObject::SetPosition(float x, float y, float z){
		const Matrix4x4&world_matrix = Parent<GameObject>()->GetWorldMatrix();
		Vector3f local_position = world_matrix.InverseMultiplyPoint3Affine(Vector3f(x, y, z));
		mLocalTransform.SetLocalPosition(local_position.x,local_position.y,local_position.z);
		Component*current = mComponents;
		while (current != nullptr){
			current->mbPositionChanged = true;
			current = current->Next<Component>();
		}
	}
	void GameObject::SetRotation(float x, float y, float z) {

	}
	void GameObject::SetScale(float x, float y, float z) {

	}
	void GameObject::SetShearing(float x, float y, float z) {
	}
	void GameObject::UpdateBoundingBox()
	{
	}

	bool GameObject::AddChild(GameObject*go){
		AppendChild(go);
		if (mbWorldMatrixDirty){
			go->mbWorldMatrixDirty;
		}
		return true;
	}
	bool GameObject::InsertBefore(GameObject*go){
		TTree::InsertBefore(go);
		if (mParent != nullptr&&Parent<GameObject>()->mbWorldMatrixDirty) {
			go->mbWorldMatrixDirty;
		}
		return true;
	}
	bool GameObject::InsertAfter(GameObject*go) {
		if (mParent!=nullptr&&Parent<GameObject>()->mbWorldMatrixDirty) {
			go->mbWorldMatrixDirty;
		}
		return TTree::InsertAfter(go);
	}

	bool GameObject::Show(){
		if (!mbEnable){
			mbEnable = true;
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnShow();
				current = next;
			}
			return true;
		}
		return false;
	}

	bool GameObject::Hide(){
		if (mbEnable){
			mbEnable = false;
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnHide();
				current = next;
			}
			return true;
		}
		return false;
	}

	bool GameObject::SetName(const char*name){
		mName = name;
		return true;
	}

	bool GameObject::SetLocalPosition(float x, float y, float z){
		mLocalTransform.SetLocalPosition(x, y, z);
		mbLocalMatrixDirty = true;
		MarkWorldMatrixDirty();
		//Debug("GameObject::SetLocalPosition %f,%f,%f",x,y,z);
		return true;
	}

	bool GameObject::SetLocalRotation(float x, float y, float z){
		mLocalTransform.SetLocalRotation(x, y, z);
		mbLocalMatrixDirty = true;
		MarkWorldMatrixDirty();
		return true;
	}

	bool GameObject::SetLocalScale(float x, float y, float z){
		mLocalTransform.SetLocalScale(x, y, z);
		mbLocalMatrixDirty = true;
		MarkWorldMatrixDirty();
		return true;
	}

	void GameObject::OnStop(){
		Component*current = mComponents;
		while (current != nullptr)
		{
			if (AudioSource::ClassID == current->GetClassID())
			{
				((AudioSource*)current)->Stop();
			}
			current = current->Next<Component>();
		}
		if (mChild!=nullptr)
		{
			((GameObject*)mChild)->OnStop();
		}
		if (mRightSibling != nullptr)
		{
			((GameObject*)mRightSibling)->OnStop(); 
		}
	}


	void GameObject::OnCollideBegin(GameObject*other)
	{
		ScriptObject*current = mScripts;
		while (current != nullptr)
		{
			current->OnCollideBegin(other);
			current = current->Next<ScriptObject>();
		}
	}

	void GameObject::OnCollideEnd(GameObject*other)
	{
		ScriptObject*current = mScripts;
		while (current != nullptr)
		{
			current->OnCollideEnd(other);
			current = current->Next<ScriptObject>();
		}
	}

	void GameObject::OnViewportChanged(float width, float height)
	{
		ScriptObject*current = mScripts;
		while (current != nullptr)
		{
			current->OnViewportChanged(width,height);
			current = current->Next<ScriptObject>();
		}
	}

	YOSEF::GameObject*GameObject::Insetersect(TouchEvent *te, bool bEditMode){
		YOSEF::GameObject*ret = nullptr;
		if (mbEnable){
			if (((GameObject*)mLastChild) != nullptr){
				ret = ((GameObject*)mLastChild)->Insetersect(te, bEditMode);
			}
			if (ret != nullptr){
				return ret;
			}
			ret = Intersect2DComponent(te->mX,te->mY, bEditMode);
			if (ret != nullptr){
				return ret;
			}
		}
		if (mLeftSibling != nullptr){
			ret = ((GameObject*)mLeftSibling)->Insetersect(te, bEditMode);
		}
		return ret;
	}

	YOSEF::GameObject*GameObject::RayCastTestRecursively(Ray*ray) {
		YOSEF::GameObject*ret = nullptr;
		if (mbEnable) {
			if (((GameObject*)mLastChild) != nullptr) {
				ret = ((GameObject*)mLastChild)->RayCastTestRecursively(ray);
			}
			if (ret != nullptr) {
				return ret;
			}
			ret = RayCastTest(ray);
			if (ret != nullptr) {
				return ret;
			}
		}
		if (mLeftSibling != nullptr) {
			ret = ((GameObject*)mLeftSibling)->RayCastTestRecursively(ray);
		}
		return ret;
	}

	GameObject* GameObject::RayCastTest(Ray*ray) {
		if (false==mbReceiveRayCast) {
			return nullptr;
		}
		return nullptr;
	}

	GameObject* GameObject::Intersect2DComponent(float x, float y, bool bEditMode) {
		if (GetEventDispatcher()->mEventListeners.find(this) == GetEventDispatcher()->mEventListeners.end()){
			if (!bEditMode) {
				return nullptr;
			}
		}
		return nullptr;
	}
	//首先根据Camera来筛选物体，Camera的depth越大，camera越靠前，该camera照射到的物体拥有更高的优先权
	//在点选时还要考虑到有的物体本身根本就不会被选中，但是在编辑器模式下，所有物体都会被选中
	//在场景中选择物体的时候，然后根据Z轴来排序，Z轴越小，越靠后
	//在Z轴一样的情况下，根据物体被加载到场景树中的先后关系来判断，先被加到场景中的物体处于后方，后来的物体处于前方，前方就是指最上面的意思
	void GameObject::OnTouchBegin(const TouchEvent&te) {
		ScriptObject*current = mScripts;
		while (current != nullptr) {
			ScriptObject*next = current->Next<ScriptObject>();
			if (current->mbEnable)current->OnTouchBegin(te);
			current = next;
		}
	}

	void GameObject::OnTouchEnd(const TouchEvent&te){
		ScriptObject*current = mScripts;
		while (current != nullptr) {
			ScriptObject*next = current->Next<ScriptObject>();
			if (current->mbEnable)current->OnTouchEnd(te);
			current = next;
		}
	}

	void GameObject::OnTouchMove(const TouchEvent&te){
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnTouchMove(te);
				current = next;
			}
		}
	}

	void GameObject::OnTouchCanceled(const TouchEvent&te){
		if (IsEnabled()){
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnTouchCanceled(te);
				current = next;
			}
		}
	}

	void GameObject::OnTouchEnter(const TouchEvent&te) {
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnTouchEnter(te);
				current = next;
			}
		}
	}

	void GameObject::OnTouchLeave(const TouchEvent&te) {
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnTouchLeave(te);
				current = next;
			}
		}
	}

	void GameObject::OnMouseWheel(const MouseWheelEvent*event) {
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnMouseWheel(event);
				current = next;
			}
		}
	}

	void GameObject::OnIMEChar(const char*utf8Str){
		if (IsEnabled()){
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnIMEChar(utf8Str);
				current = next;
			}
		}
	}

	void GameObject::OnIMECompositionString(const char*utf8Str,bool isResult) {
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnIMECompositionString(utf8Str,isResult);
				current = next;
			}
		}
	}
	
	void GameObject::OnEditEnd(){
        if (IsEnabled()){
            ScriptObject*current = mScripts;
            while (current != nullptr) {
                ScriptObject*next = current->Next<ScriptObject>();
                if (current->mbEnable)current->OnEditEnd();
                current = next;
            }
        }
    }

	void GameObject::OnChar(YOSEFUInt32 charCode){
		if (IsEnabled()){
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnChar(charCode);
				current = next;
			}
		}
	}

	void GameObject::OnKeyDown(int code){
		if (IsEnabled()){
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnKeyDown(code);
				current = next;
			}
		}
	}

	void GameObject::OnKeyUp(int code){
		if (IsEnabled()){
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnKeyUp(code);
				current = next;
			}
		}
	}

	void GameObject::OnAnimationEnd(const char*name) {
		if (IsEnabled()) {
			ScriptObject*current = mScripts;
			while (current != nullptr) {
				ScriptObject*next = current->Next<ScriptObject>();
				if (current->mbEnable)current->OnAnimationEnd(name);
				current = next;
			}
		}
	}
}
