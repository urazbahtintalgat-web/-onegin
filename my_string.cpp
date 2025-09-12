#include "my_string.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
* @brief Эта функция печатает строку с последующим \н
*/
void my_puts(const char *str) {
    assert(str);

    for (size_t i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

/**
*@brief Эта функция ищет первое вхождение символа ch в строку, иначе НУЛЛ
*/
char *my_strchr(const char *str, int ch) {
    assert(str);

    char c = (char)ch;
    const char* ans = NULL;//const

    for (size_t i = 0; str[i] != '\0'; i++) {

        if (str[i] == c) {

            ans = str + i;
            break;
        }
    }
    return(char*)ans;//(char*)
}

/**
*@brief Эта функция считает длину строки без \0
*/
size_t my_strlen(const char *str) {
    assert(str);

    size_t i = 0;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

/**
*@brief Эта функция копирует символы из строки srcptr в строку destptr
*/
char *my_strcpy(char *destptr, const char *srcptr) {//zach vozvrachat ptr
    assert(destptr);
    assert(srcptr);

    size_t i = 0;
    while ((destptr[i] = srcptr[i]) != '\0') {
        i++;
    }
    return destptr;
}

/**
*@brief Эта функция копирует первые num символов из строки srcptr в строку destptr
*/
char *my_strncpy(char *destptr, const char *srcptr, size_t num){//zach vozvrachat ptr
    assert(destptr);
    assert(srcptr);

    size_t i = 0;
    for (i = 0; i < num && srcptr[i] != '\0'; i++) {
        destptr[i] = srcptr[i];
    }
    destptr[i] = '\0';
    return destptr;
}

/**
*@brief Эта функция добавляет копию строки srcptr в конец строки destptr
*/
char *my_strcat(char *destptr, const char *srcptr ) {
    assert(destptr);
    assert(srcptr);

    size_t to_len = my_strlen(destptr);

    size_t i = to_len;
    for (i = to_len; srcptr[i - to_len] != '\0'; i++) {
        destptr[i] = srcptr[i - to_len];
    }
    destptr[i] = '\0';
    return destptr;
}

/**
*@brief Эта функция добавляет первые num символов строки srcptr в конец строки destptr
*/
char *my_strncat(char *destptr,const char *srcptr, size_t num) {
    assert(destptr);
    assert(srcptr);

    size_t to_len = my_strlen(destptr);

    size_t i = to_len;
    for (i = to_len; srcptr[i - to_len] != '\0' && i - to_len < num; i++) {
        destptr[i] = srcptr[i - to_len];
    }
    destptr[i] = '\0';
    return destptr;
}

/**
*@brief Эта Функция fgets считывает символы из потока и сохраняет их в виде строки
*       в параметр string до тех пор пока не наступит конец строки или пока не будет
*       достигнут конец файла.(num - макс количество символов)
*/
char *my_fgets(char *string, int num, FILE *filestream) {
    if (string == NULL || num <= 0 || filestream == NULL){
        return NULL;
    }

    size_t i = 0;

    for (i = 0; i < num - 1; i++) {
        int ch = getc(filestream);

        if (ch == EOF) {
            if (i == 0) {
                return NULL;
            }
            break;
        }
        string[i] = (char)ch;

        if (ch == '\n') {
            break;
        }
    }
    string[i + 1] = '\0';
    return string;
}

/**
*@brief Эта функция считывает строку и переводит ее в целое число пока не встретит
*       любую не цифру
*/
int my_atoi(const char * string) {
    assert(string);

    int ans = 0;
    size_t i = 0;
    while (string[i] == ' ') {
        i++;
    }
    char znak = '+';
    if (string[i] == '-') {
        znak = '-';
        i++;
    }
    while ('0' <= string[i] && string[i] <= '9') {
        ans *= 10;
        ans += (int) (string[i] - '0');
        i++;
    }
    if (znak == '+') {
        return ans;
    } else {
        return -ans;
    }
}

/**
*@brief Эта функция возвращает указатель на завершающуюся нулём байтовую строку,
*       является дубликатом строки, на которую указывает s
*/
char *my_strdup(const char *s) {
    if (!s) return NULL;

    char *ans = NULL;
    int len = my_strlen(s) + 1;
    ans = (char *) calloc(len, sizeof(char));

    my_strcpy(ans, s);

    return ans;
}

/**
*@brief Эта функция считывает строку из файла до первого \н или до конца файла с конечным \0
*/
ssize_t my_getline(char** lineptr, size_t* n, FILE* stream) {
    if (!lineptr || !n || !stream) return -1;

    size_t size = 32;
    if (*lineptr) {
        assert(*n != 0);
        size = *n;
    }

    ssize_t i = 0;
    if (!*lineptr) {
        *lineptr = (char *) calloc(size, sizeof(char));
    }

    char ch = 0;
    char *shit = NULL;
    while ((ch = getc(stream)) != '\n' && ch != EOF) {
        if (i == size - 1){
            size *= 2;
            shit = (char *) realloc(*lineptr, size);
            if (shit == NULL) {
                free(*lineptr);
                return -1;
            }
            *lineptr = shit;
        }
        *(*lineptr + i) = ch;
        i++;
    }
    if (i == 0) {
        return -1;
    }
    if (ch == '\n'){
        *(*lineptr + i) = '\n';
        i++;
    }
    *(*lineptr + i) = '\0';
    return i;
}

/**
*@brief Эта функция находит первое вхождение строки string2 в строку в string1 иначе null
*/
const char * my_strstr(const char * string1, const char * string2) {
// haystack needle // str substr
    if (string2 == NULL || *string2 == '\0') {
        return string1;
    }

    if (string1 == NULL) {
        return NULL;
    }

    size_t i = 0;
    while (string1[i] != '\0') {
        size_t j = 0;
        while (string1[i+j] != '\0' && string2[j] != '\0' &&
               string1[i + j] == string2[j]) {
            j++;
        }
        if (string2[j] == '\0') {
            return string1 + i;
        }
        i++;
    }
    return NULL;
}
//char * strtok(char * string, const char * delim) {
//    static int n = -1;
//    n++;
//    static char my_string[] = string;
//    size_t len_delim = my_strlen(delim);
//    size_t i = 0;
//    int numberof0 = 0;
//    while (numberof0 < n || my_string[i] != '\0') {
//
