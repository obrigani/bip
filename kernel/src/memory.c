#include "memory.h"
#include <stddef.h>

int memcmp(const void *ptagret1, const void *ptarget2, size_t size)
{
  const unsigned char* ptrgt1 = (const unsigned char*) ptagret1;
  const unsigned char* ptrgt2 = (const unsigned char*) ptarget2;
  for(size_t i = 0; i < size; i++) {
    if(ptrgt1[i] < ptrgt2[i])
      return -1;
    else if(ptrgt1[i] < ptrgt2[i])
      return 1;
  }
  return 0;
}

void* memcpy(void* restrict ptarget, const void* restrict psource, size_t size)
{
  unsigned char* ptrgt = (unsigned char*) ptarget;
  const unsigned char* psrc = (const unsigned char*) psource;
  for(size_t i = 0; i < size; i++)
    ptrgt[i] = psrc[i];
  return ptarget;  
}

void* memmove(void* ptarget, const void* psource, size_t size)
{
  unsigned char* ptrgt = (unsigned char*) ptarget;
  const unsigned char* psrc = (const unsigned char*) psource;
  if(ptrgt < psrc) {
    for(size_t i = 0; i < size; i++)
      ptrgt[i] = psrc[i];
  } else {
    for(size_t i = size; i != 0; i--)
      ptrgt[i - 1] = psrc[i - 1];
  }
  return ptarget;
}

void* memset(void* pbuffer, int value, size_t size)
{
  unsigned char* pbuf = (unsigned char*) pbuffer;
  for(size_t i = 0; i < size; i++)
    pbuf[i] = (unsigned char) value;
  return pbuffer;
}

size_t strlen(const char* str)
{
  size_t len = 0;
  while(str[len]) len++;
  return len;
}
