#ifndef MY_STRING
#define MY_STRING
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

/**
 * @brief структура чтобы хранить начало и конец строки не включая \н и без \0
 */
struct line {
    char* begin;
    char* end;
};

/**
* @brief Эта функция печатает строку с последующим \н
*/
void my_puts(const char *str);

/**
*@brief Эта функция ищет первое вхождение символа ch в строку, иначе НУЛЛ
*/
char *my_strchr(const char *str, int ch);

/**
*@brief Эта функция считает длину строки без \0
*/
size_t my_strlen(const char *str);

/**
*@brief Эта функция копирует символы из строки srcptr в строку destptr
*/
char *my_strcpy(char *destptr, const char *srcptr);

/**
*@brief Эта функция копирует первые num символов из строки srcptr в строку destptr
*/
char *my_strncpy(char *destptr, const char *srcptr, size_t num);

/**
*@brief Эта функция добавляет копию строки srcptr в конец строки destptr
*/
char *my_strcat(char *destptr, const char *srcptr );

/**
*@brief Эта функция добавляет первые num символов строки srcptr в конец строки destptr
*/
char *my_strncat(char *destptr,const char *srcptr, size_t num);

/**
*@brief Эта Функция fgets считывает символы из потока и сохраняет их в виде строки
*       в параметр string до тех пор пока не наступит конец строки или пока не будет
*       достигнут конец файла.(num - макс количество символов)
*/
char *my_fgets(char *string, int num, FILE *filestream);

/**
*@brief Эта функция считывает строку и переводит ее в целое число пока не встретит
*       любую не цифру
*/
int my_atoi(const char * string);

/**
*@brief Эта функция возвращает указатель на завершающуюся нулём байтовую строку,
*       является дубликатом строки, на которую указывает s
*/
char *my_strdup(const char *s);

/**
*@brief Эта функция считывает строку из файла до первого \н или до конца файла с конечным \0
*/
ssize_t my_getline(char** lineptr, size_t* n, FILE* stream);

/**
*@brief Эта функция находит первое вхождение строки string2 в строку в string1 иначе null
*/
const char * my_strstr(const char * string1, const char * string2);

ssize_t my_getword(char** lineptr, size_t* n, FILE* stream);

int repstrcmp(char* str1, char* str2);

char* find_first_alpha(char* start_line, char* end_line);

char* find_last_alpha(char* start_line, char* end_line);

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
#endif //MY_STRING
