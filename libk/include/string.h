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

#pragma once

#include <stddef.h>

int memcmp(const void* ptagret1, const void* ptarget2, size_t);
void* memcpy(void* __restrict ptarget, const void* __restrict psource, size_t size);
void* memmove(void* ptarget, const void* psource, size_t size);
void* memset(void* pbuffer, int value, size_t size);
size_t strlen(const char* str);
