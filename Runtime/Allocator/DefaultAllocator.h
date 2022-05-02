#pragma once
#include <new>
#include "MemoryLabel.h"
#define YOSEF_ALIGN 4
#define YOSEF_ADJUST_MEMORY_SIZE(size) ((size + (YOSEF_ALIGN - 1)) & ~(YOSEF_ALIGN - 1))
void*operator new(std::size_t size);
void*operator new(std::size_t size, MemoryLabel memID);
void*operator new[](std::size_t size, MemoryLabel memID);

#if YOSEF_ANDROID||YOSEF_IPHONE
void operator delete[](void*ptr)noexcept(true);
void operator delete(void*ptr) noexcept(true);
#else
void operator delete[](void*ptr);
void operator delete(void*ptr);
#endif
void operator delete(void*ptr, MemoryLabel memID);
void operator delete[](void*ptr, MemoryLabel memID);