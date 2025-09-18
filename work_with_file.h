#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H
#include <stdio.h>

/**
 * @brief структура чтобы хранить начало и конец строки не включая \н и без \0
 */
struct line {
    char* begin;
    char* end;
};

char* readfile(char* file_name, size_t *read);

int count_lines(const char* line_massive);

struct line* make_ptr_massive(char* line_massive, int line_amount);

int compare_fumction_for_line(const void * ptr1, const void *ptr2);

int reverse_compare_fumction_for_line(const void * ptr1, const void *ptr2);

#endif //WORK_WITH_FILE_H