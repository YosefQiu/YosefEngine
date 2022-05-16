#include "Runtime/Allocator/tlsf/tlsf.h"
#include <stdio.h>
#include <stdlib.h>
#include <new>
class A
{
public:
	int a, b;
	A()
	{
		printf("AAAAAAAAAAA\n");
	}
};

tlsf_t tlsf4;

void* operator new(size_t size)
{
	printf("the test of overload new\n");
	return tlsf_malloc(tlsf4, size);
}
void* operator new[] (size_t size)
{
	printf("the test of overload new\n");
	return tlsf_malloc(tlsf4, size);
}

void operator delete(void* ptr)
{
	tlsf_free(tlsf4, ptr);
}

void operator delete[](void* ptr)
{
	tlsf_free(tlsf4, ptr);
}

enum MemLabel
{
	kMemDefault, kMemMesh, kMemAudio
};

void* operator new(size_t size, MemLabel mem)
{
	printf("the test of overload new\n");
	return tlsf_malloc(tlsf4, size);
}
void* operator new[](size_t size, MemLabel mem)
{
	printf("the test of overload new\n");
	return tlsf_malloc(tlsf4, size);
}

void operator delete(void* ptr, MemLabel mem)
{
	tlsf_free(tlsf4, ptr);
}

void operator delete[](void* ptr, MemLabel mem)
{
	tlsf_free(tlsf4, ptr);
}

int main(int argc, char** argv)
{
	printf("Test for TLSF--------------\n");

	printf("Basic operation of TLSF----------\n");
	char szBuffer[102400] = { 0 };
	tlsf_t tlsf = tlsf_create_with_pool(szBuffer, 102400);
	pool_t pool = tlsf_get_pool(tlsf);
	printf("align size %d\n", tlsf_align_size());
	printf("min block size %d\n", tlsf_block_size_min());
	printf("max block size %d\n", tlsf_block_size_max());

	void* ptr = tlsf_malloc(tlsf, 3);
	printf("memory block size of ptr %d\n", tlsf_block_size(ptr));
	
	void* ptr1 = tlsf_memalign(tlsf, 16, 27);
	printf("memory block size of ptr1 %p %d\n", ptr1, tlsf_block_size(ptr1));

	ptr1 = tlsf_realloc(tlsf, ptr1, 32);
	printf("memory block size of ptr1 %p %d\n", ptr1, tlsf_block_size(ptr1));

	char szBuffer2[102400];
	pool_t pool2 = tlsf_add_pool(tlsf, szBuffer2, 102400);

	tlsf_remove_pool(tlsf, pool2);

	tlsf_malloc(tlsf, 12);

	tlsf_free(tlsf, ptr);
	tlsf_free(tlsf, ptr1);

	printf("new object on the specified memory block----------\n");
	printf("size of A %d\n", sizeof(A));
	
	void* szBuffer3 = malloc(102400000);
	tlsf_t tlsf2 = tlsf_create_with_pool(szBuffer3, 102400000);
	pool_t pool3 = tlsf_get_pool(tlsf2);
	void* ptr3 = tlsf_malloc(tlsf2, sizeof(A));
	A* a = new (ptr3)A;
	printf("a %p vs ptr3 %p\n", a, ptr3);
	a->a = 1;
	a->b = 2;
	//delete a;
	free(szBuffer3);
	
	printf("overload new operation----------\n");
	void* szBuffer4 = malloc(102400000);
	tlsf4 = tlsf_create_with_pool(szBuffer4, 102400000);
	A* b = new A[3];
	b->a = 1;
	b->b = 2;
	delete[] b;
	
	
	printf("add label to memory----------\n");
	A* c = new (kMemDefault)A;

	free(szBuffer4);
	system("pause");
	return 0;
}