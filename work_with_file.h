#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H
#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief структура чтобы хранить начало и конец строки не включая \н и без \0
 */
struct line {
    char* begin;
    char* end;
};

/**
 * @brief Эта функция возвращает размер файла в байтах
 * 
 * @param file_name имя файла размер которого надо определить
 * 
 * @return размер файла в байтах либо -1 если открыть файл не вышло
 */
long int get_file_length(char* file_name);

/**
 * @brief Эта функция считывает весь текстовый файл
 * 
 * @param file_name строка путь до твекстового файла
 * @param read указатель на число куда сохраняется количество считанных элементов
 * 
 * @return указатель на выделенную динамическую память в которую скопировался файл
 */
char* readfile(char* file_name, size_t *read);

/**
 * @brief эта функция считает количество строк в массиве где идут строки и между ними \н
 * 
 * @param line_massive указатель на длинную строку внутри которой много разных через \н
 * 
 * @return возвращает количество строк
 */
int count_lines(const char* line_massive);

/**
 * @brief эта функция возвращает динамически выделенную память в которой содержиться массив
 *        структур для хранения указателя на начало и конец каждого слова
 * 
 * @param line_massive массив чаров который является множеством строк идущих подряд
 * @param line_amount количество строк
 * 
 * @return указатель на выделенный динамически массив из структур
 */
struct line* make_line_massive(char* line_massive, int line_amount);

/**
 * @brief функция сравнения для line под стандарт qsort
 * 
 * @param ptr1 указатель на 1 line
 * @param ptr2 указатель на 2 line
 * 
 * @return <0 если line1 < line2, 0 если line1 == line2, >0 если line1 > line2
 */
int compare_fumction_for_line(const void * ptr1, const void *ptr2);

/**
 * @brief функция сравнения с конца для line под стандарт qsort
 * 
 * @param ptr1 указатель на 1 line
 * @param ptr2 указатель на 2 line
 * 
 * @return <0 если line1 < line2, 0 если line1 == line2, >0 если line1 > line2 (все это с конца)
 */
int reverse_compare_fumction_for_line(const void * ptr1, const void *ptr2);

#endif //WORK_WITH_FILE_H