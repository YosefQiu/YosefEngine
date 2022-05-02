#pragma once

namespace YOSEF {
	class LinkedList
	{
	public:
		LinkedList() :mNext(nullptr) {}
	public:
		virtual void PushBack(LinkedList* pNode)
		{
			if (mNext == nullptr)
			{
				mNext = pNode;
			}
			else
			{
				if (mNext == pNode)
					return;
				Next<LinkedList>()->PushBack(pNode);
			}
		}
		virtual void Remove(LinkedList* pNode)
		{
			if (mNext != nullptr)
			{
				if (pNode == mNext)
				{
					mNext = pNode->Next<LinkedList>();
					pNode->mNext = nullptr;
				}
				else
				{
					Next<LinkedList>()->Remove(pNode);
				}
			}
		}
	public:
		LinkedList* mNext;
		template<typename T>
		T* Next()
		{
			return (T*)mNext;
		}
	};
	class DoubleLinkedList
	{
	public:
		DoubleLinkedList() :mNext(nullptr), mPrev(nullptr) {}
		virtual ~DoubleLinkedList()
		{
			LeaveList();
		}
		// move up
		void operator<<(int nGAP)
		{
			DoubleLinkedList* pNodeToShift = this;
			DoubleLinkedList* pTargetPos = Prev<DoubleLinkedList>();
			while (--nGAP)
			{
				pTargetPos = pTargetPos->Prev<DoubleLinkedList>();
			}
			pNodeToShift->InsertBefore(pTargetPos);
		}
		//move down
		void operator>>(int nGAP)
		{
			DoubleLinkedList* pNodeToShift = this;
			DoubleLinkedList* pTargetPos = Next<DoubleLinkedList>();
			while (--nGAP)
			{
				pTargetPos = pTargetPos->Next<DoubleLinkedList>();
			}
			pNodeToShift->InsertAfter(pTargetPos);
		}
		void Append(DoubleLinkedList* pNode)
		{
			if (mNext != nullptr)
			{
				mNext->Append(pNode);
			}
			else
			{
				mNext = pNode;
				pNode->mPrev = this;
			}
		}
		void InsertBefore(DoubleLinkedList* pNode)
		{
			LeaveList();
			if (pNode->mPrev != nullptr)
			{
				pNode->mPrev->mNext = this;
			}
			mPrev = pNode->mPrev;
			pNode->mPrev = this;
		}
		void InsertAfter(DoubleLinkedList* pNode)
		{
			LeaveList();
			if (pNode->mNext != nullptr)
			{
				pNode->mNext->mPrev = this;
			}
			mNext = pNode->mNext;
			pNode->mNext = this;
			mPrev = pNode;
		}
		void LeaveList()
		{
			if (mPrev != nullptr)
			{
				mPrev->mNext = mNext;
			}
			if (mNext != nullptr)
			{
				mNext->mPrev = mPrev;
			}
			mPrev = nullptr;
			mNext = nullptr;
		}
	public:
		DoubleLinkedList* mPrev;
		DoubleLinkedList* mNext;
	public:
		template<typename T>
		T* Next()
		{
			return (T*)mNext;
		}
		template<typename T>
		T* Prev()
		{
			return (T*)mPrev;
		}
	};
}