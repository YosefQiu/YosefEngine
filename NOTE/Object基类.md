## Object Base Class

-----



[toc]

```mermaid
graph TD
L["Function (String Class,Math Class,TLSF,Log,etc)"] --> A[Object Class] --> B[Component Class] --> C[Component2D Class]
B --> K[Component3D Class]
A --> D[Lua Class]
A --> N[etc]
C --> E[Label]
C --> F[Image Sprite]
C --> H[Image Sprite 9]
C --> M[etc]
K --> Z[Mesh]
K --> Y[Model]
K --> W[etc]
```



```c++
class Object 
{
public:
	Object(int autorelease = 1);
	virtual ~Object();
public:
	YOSEFSInt32 mReferenceCount;
	int mLuaData;
	int mObjectMask;
public:
	void retain();
	void release();
};
```

