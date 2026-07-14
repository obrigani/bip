/*
 * bip - Bip Is Perfect
 * Copyright (C) 2026  obrigani team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3 of the License
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string.h>
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
