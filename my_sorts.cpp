#include "my_sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap(void * first, void * second, size_t size) {
    char * a = (char *) first;
    char * b = (char *) second;
    while (size--) {
        char buff = *a;
        *a    = *b;
        *b    = buff;
        a++;
        b++;
    }
}


void buble_sort(void* first, size_t number, size_t size, int (* comparator) (const void *, const void *)) {
    assert(comparator);
    assert(first);
    assert(number >= 0);
    assert(size >= 1);

    //void * buff = malloc(size);
    //assert(buff);

    char * buff_first = (char*) first;



    for (size_t sorted = 0; sorted < number; sorted++) {
        for (size_t j = 0; j < number - sorted - 1; j++) {
            void * now  = buff_first + j * size;
            void * next = buff_first + (j + 1) * size;

            if (comparator(now, next) > 0) {
                swap(now, next, size);
            }
        }
    }

    //free(buff);
}