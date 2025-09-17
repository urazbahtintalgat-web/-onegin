#ifndef MY_STRING
#define MY_STRING
#include <stdio.h>

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
#endif //MY_STRING
