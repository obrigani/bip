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

#include <stddef.h>

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

