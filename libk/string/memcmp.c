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

