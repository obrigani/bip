#pragma once

#include <stddef.h>

int memcmp(const void* ptagret1, const void* ptarget2, size_t);
void* memcpy(void* __restrict ptarget, const void* __restrict psource, size_t size);
void* memmove(void* ptarget, const void* psource, size_t size);
void* memset(void* pbuffer, int value, size_t size);
size_t strlen(const char* str);
