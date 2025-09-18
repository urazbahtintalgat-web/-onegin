#include "work_with_file.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

/**
 * @brief Эта функция считывает весь текстовый файл
 * 
 * @param file_name строка путь до твекстового файла
 * @param read указатель на число куда сохраняется количество считанных элементов
 * 
 * @return указатель на выделенную динамическую память в которую скопировался файл
 */
char* readfile(char* file_name, size_t *read) {
    struct stat text_stat;
    int n = stat(file_name, &text_stat);
    long int size_text = text_stat.st_size;

    char* massiv = (char*) calloc(size_text + 1, sizeof(char));
    assert(massiv);

    FILE* text = fopen(file_name, "r");
    assert(text);

    *read = fread(massiv, sizeof(char), size_text, text);
    massiv[*read] = '\0';
    return massiv;
}

/**
 * @brief эта функция считает количество строк в массиве где идут строки и между ними \н
 * 
 * @param line_massive указатель на длинную строку внутри которой много разных через \н
 * 
 * @return возвращает количество строк
 */
int count_lines(const char* line_massive) {
    assert(line_massive);

    char* ind = (char*) line_massive;
    int amount = 1;
    while (ind = strchr(ind, '\n')) {
        amount++;
        ind++;
    }
    return amount;
}

/**
 * @brief эта функция возвращает динамически выделенную память в которой содержиться массив
 *        структур для хранения указателя на начало и конец каждого слова
 * 
 * @param line_massive массив чаров который является множеством строк идущих подряд
 * @param line_amount количество строк
 * 
 * @return указатель на выделенный динамически массив из структур
 */
struct line* make_ptr_massive(char* line_massive, int line_amount) {
    struct line * ptr_massiv;
    ptr_massiv = (struct line *) calloc(line_amount, sizeof(struct line));

    int n = 0;
    ptr_massiv[0].begin = line_massive;

    char* ind = line_massive;
    char* saved_ind = ind;
    while (ind = strchr(ind, '\n')) {
        ptr_massiv[n].end = ind - 1;
        n++;
        ptr_massiv[n].begin = ind + 1;
        saved_ind = ind;
        ind++;
    }
    while (*saved_ind != '\0') {
        saved_ind++;
    }
    ptr_massiv[n].end = saved_ind;
    assert(line_amount == n + 1);

    return ptr_massiv;
}

/**
 * @brief функция сравнения для line под стандарт qsort
 * 
 * @param ptr1 указатель на 1 line
 * @param ptr2 указатель на 2 line
 * 
 * @return <0 если line1 < line2, 0 если line1 == line2, >0 если line1 > line2
 */
int compare_fumction_for_line(const void * ptr1, const void *ptr2) {
    assert(ptr1);
    assert(ptr2);

    struct line * p1 = (struct line *) ptr1;
    struct line * p2 = (struct line *) ptr2;
    assert(p1->begin && p1->end && p2->begin && p2->end);

    char* start1 = p1->begin;
    char* start2 = p2->begin;

    while (start1 <= p1->end && !isalpha(*start1)) {
        start1++;
    }
    while (start2 <= p2->end && !isalpha(*start2)) {
        start2++;
    }

    int has_letters1 = (start1 <= p1->end);
    int has_letters2 = (start2 <= p2->end);

    if (!has_letters1 && !has_letters2) return 0;
    if (!has_letters1) return -1;
    if (!has_letters2) return 1;

    size_t len1 = p1->end - start1 + 1;
    size_t len2 = p2->end - start2 + 1;
    size_t min_len = (len1 > len2) ? len2 : len1;
    
    int cmp = memcmp(start1, start2, min_len);

    if (cmp != 0) {
        return cmp;
    }

    if (len1 == len2) {
        return 0;
    } else if (len1 < len2) {
        return -1;
    } else {
        return 1;
    }
}

int reverse_compare_fumction_for_line(const void * ptr1, const void *ptr2) {
    assert(ptr1);
    assert(ptr2);

    struct line * p1 = (struct line *) ptr1;
    struct line * p2 = (struct line *) ptr2;
    assert(p1->begin && p1->end && p2->begin && p2->end);

    char* end1 = p1->end;
    char* end2 = p2->end;

    while (end1 >= p1->begin && !isalpha(*end1)) {
        end1--;
    }
    while (end2 >= p2->begin && !isalpha(*end2)) {
        end2--;
    }

    while(end1 >= p1->begin && end2 >= p2->begin && tolower(*end1) == tolower(*end2)) {
        end1--;
        end2--;
    }

    if (end1 < p1->begin && end2 < p2->begin) {
        return 0;
    }else if (end1 < p1->begin) {
        return -1;
    }else if (end2 < p2->begin) {
        return 1;
    }

    return (unsigned char)tolower(*end1) - (unsigned char)tolower(*end2);
}