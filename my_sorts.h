#ifndef MY_SORTS_H
#define MY_SORTS_H

#include <stdio.h>
typedef int camporator_type;

void swap(void * first, void * second);

void buble_sort(void* first, size_t number, size_t size, camporator_type (* comparator) (const void *, const void *));

#endif //MY_SORTS_H