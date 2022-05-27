#include <iostream>
#include "smartptr.h"

using namespace std;

class Base
{
public:
	int mReferenceCount;
	void retain()
	{
		mReferenceCount++;
		cout << "retain()" << " " << mReferenceCount << endl;
	}
	void release()
	{
		mReferenceCount--;
		cout << "release()" << " " << mReferenceCount << endl;
		if (mReferenceCount == 0)
			delete this;
	}
	Base() :mReferenceCount(0)
	{
		cout << "Base()" << endl;
	}
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class A : public Base
{
public:
	bool a;
	int b;
	char c;
	A()
	{
		printf("A()\n");
	}
	~A()
	{
		printf("~A()\n");
	}
	void Func()
	{
		cout << "a " << a << endl;
		cout << "b " << b << endl;
		cout << "c " << c << endl;
	}
};

int main()
{
	cout << "Test for SmartPtr----------- " << endl;
	{
		SmartPtr<A> aa = new A;
		aa->a = true;
		aa->b = 2;
		aa->c = 'c';
		aa->Func();
	}
	
	system("pause");
	return 0;
}