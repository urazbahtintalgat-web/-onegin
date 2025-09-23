#ifndef MY_SORTS_H
#define MY_SORTS_H

#include <stdio.h>

void buble_sort(void* first, size_t number, size_t size, int (* comparator) (const void *, const void *));

#endif //MY_SORTS_H