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
    if (!lineptr || !n || !stream) {
        return -1;
    }

    size_t size = *n;
    if (*lineptr == NULL || size == 0) {
        size = 32;
        char *new_ptr = (char*) realloc(*lineptr, size);
        if (new_ptr == NULL) {
            return -1;
        }
        *lineptr = new_ptr;
        *n = size;
    }

    ssize_t i = 0;
    int ch;

    while ((ch = getc(stream)) != EOF) {
        if (i >= (ssize_t)(size - 1)) {
            size *= 2;
            char *new_ptr = (char *) realloc(*lineptr, size);
            if (new_ptr == NULL) {
                if (*lineptr && i > 0) {
                    (*lineptr)[i] = '\0';
                }
                return -1;
            }
            *lineptr = new_ptr;
            *n = size;
        }

        (*lineptr)[i++] = (char)ch;

        if (ch == '\n') {
            break;
        }
    }

    if (i == 0 && ch == EOF) {
        return -1;
    }

    if (*lineptr) {
        (*lineptr)[i] = '\0';
    }

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

/**
 * @brief Эта функция считывает строку из файла до первого символа разделителя:
 *        ('\n', ' ', ',', '.', '?', '!', '(', ')', ';', '_')
 * 
 * @return Количество считанных символов учитывая разделитель но заменяя его на \0
 */
ssize_t my_getword(char** lineptr, size_t* n, FILE* stream) {
    if (!lineptr || !n || !stream) {
        return -1;
    }

    size_t size = *n;
    if (*lineptr == NULL || size == 0) {
        size = 8;
        char *new_ptr = (char*) realloc(*lineptr, size);
        if (new_ptr == NULL) {
            return -1;
        }
        *lineptr = new_ptr;
        *n = size;
    }

    ssize_t i = 0;
    int ch = 0;

    while ((ch = getc(stream)) != EOF) {
        if (i >= (ssize_t)(size - 1)) {
            size *= 2;
            char *new_ptr = (char *) realloc(*lineptr, size);
            if (new_ptr == NULL) {
                if (*lineptr && i > 0) {
                    (*lineptr)[i] = '\0';
                }
                return -1;
            }
            *lineptr = new_ptr;
            *n = size;
        }

        (*lineptr)[i++] = (char)ch;

        if (ch == '\n' || ch == ' ' || ch == ',' || ch == '.' || ch == '!' || ch == ';' || ch == '_'
            || ch == '(' || ch == ')' || ch == '?') {
            //i--;
            break;
        }
    }

    if (i == 0 && ch == EOF) {
        return -1;
    }

    if (*lineptr) {
        (*lineptr)[i - 1] = '\0';
    }

    return i;
}

int repstrcmp(char* str1, char* str2) {
    int ind1 = 0, ind2 = 0;

    while (str1[ind1] != '\0')
        ind1++;
    while (str2[ind2] != '\0')
        ind2++;
    
    while (str1[ind1] == str2[ind2] && ind1 >= 0 && ind2 >= 0) {
        ind1--;
        ind2--;
    }

    if (ind1 == -1 && ind2 == -1) {
        return 0;
    } else if (ind1 == -1) {
        return -1;
    } else if (ind2 == -1) {
        return 1;
    } else {
        return str1[ind1] - str2[ind2];
    }
}

char* find_first_alpha(char* start_line, char* end_line) {
    while (start_line <= end_line && !isalpha(*start_line)) {
        start_line++;
    }
    return start_line;
}

char* find_last_alpha(char* start_line, char* end_line) {
    while (end_line >= start_line && !isalpha(*end_line)) {
        end_line--;
    }
    return end_line;
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

    start1 = find_first_alpha(p1->begin, p1->end);
    start2 = find_first_alpha(p2->begin, p2->end);

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

/**
 * @brief функция сравнения с конца для line под стандарт qsort
 * 
 * @param ptr1 указатель на 1 line
 * @param ptr2 указатель на 2 line
 * 
 * @return <0 если line1 < line2, 0 если line1 == line2, >0 если line1 > line2 (все это с конца)
 */
int reverse_compare_fumction_for_line(const void * ptr1, const void *ptr2) {
    assert(ptr1);
    assert(ptr2);

    struct line * p1 = (struct line *) ptr1;
    struct line * p2 = (struct line *) ptr2;
    assert(p1->begin && p1->end && p2->begin && p2->end);

    char* end1 = p1->end;
    char* end2 = p2->end;

    end1 = find_last_alpha(p1->begin, end1);
    end2 = find_first_alpha(p2->begin, end2);

    while(end1 >= p1->begin && end2 >= p2->begin && tolower(*end1) == tolower(*end2)) {
        end1--;
        end2--;
    }

    if (end1 < p1->begin && end2 < p2->begin) {
        return 0;
    } else if (end1 < p1->begin) {
        return -1;
    } else if (end2 < p2->begin) {
        return 1;
    }

    return tolower(*end1) - tolower(*end2);
}
