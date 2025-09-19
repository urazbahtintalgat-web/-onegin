#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

#include "my_string.h"
#include "onegin_reader.h"
#include "work_with_file.h"

int MAXSTRINGS = 1000;

void swap_str(char* str1, char* str2) {
    for (int i = 0; i < 100; i++) {
        str1[i] ^= str2[i];
        str2[i] ^= str1[i];
        str1[i] ^= str2[i];
    }
}

void swap_ptr(char** ptr1, char** ptr2) {
    char* buff = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = buff;
    return;
}

int lexcmp(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

int sravnenie_rep(char* str1, char* str2);

int main(){
    size_t read = 0;
    char file_name[] = "textonegin.txt";
    char* massiv = readfile(file_name , &read);
    if (massiv == NULL) {
        printf("file was not opened\n");
        return 1;
    }

    int line_amount = count_lines(massiv);
    printf("%d\n", line_amount);

    struct line * lines = make_ptr_massive(massiv, line_amount);
    if (lines == NULL) {
        printf("memory was not allocated\n");
        return 1;
    }

    char* start = lines[0].begin;
    char* end = lines[line_amount-1].end;

    char result_file[] = "resultonegin.txt";
    FILE* fd = fopen(result_file, "w");

    //сортировка и запиьс по алфавиту
    qsort(lines, (size_t) line_amount, sizeof(struct line), compare_fumction_for_line);

    for (int i = 0; i < line_amount; i++) {
        fwrite(lines[i].begin, sizeof(char), (size_t) (lines[i].end - lines[i].begin + 1), fd);
        fputc('\n', fd);
    }

    //fprintf(fd, "\n\n\n");

    //сортировка с конца
    qsort(lines, (size_t) line_amount, sizeof(struct line), reverse_compare_fumction_for_line);

    for (int i = 0; i < line_amount; i++) {
        fwrite(lines[i].begin, sizeof(char), (size_t) (lines[i].end - lines[i].begin + 1), fd);
        fputc('\n', fd);
    }
    
    //fprintf(fd, "\n\n\n");

    //обычная запись

    fwrite(start, sizeof(char), (size_t) (end - start), fd);

    fclose(fd);

    
    //
    //for (int i = 0; i < line_amount; i++) {
    //    char* ind = ptr_massiv[i].begin;
    //    while (ind <= ptr_massiv[i].end) {
    //        printf("%c", *ind++);
    //    }
    //    printf("\n");
    //}
    

    /*
    //--------------------------------------------------------странный момент с последовательностью
    //первое чтение
    char** mas;
    mas = (char **) malloc(MAXSTRINGS * sizeof(char*));
    FILE* res = fopen("result.txt", "w");
    int n = onegin_reader(text, &mas, &MAXSTRINGS);

    //второе чтение
    rewind(text);
    char** repmas;
    repmas = (char **) malloc(MAXSTRINGS * sizeof(char*));
    FILE* repres = fopen("represult.txt" , "w");
    int repn = onegin_reader(text, &repmas, &MAXSTRINGS);
    
    fclose(text);
    //----------------------------------------------------------------------------------------------


    //sort----------------------------------------------
    qsort(mas, (size_t) n, sizeof(char*), lexcmp);
    
    for (int i = 0; i < n; i++) {
        //
        //printf("%d\n", i);
        //printf("%s", mas[i]);
        if (i > 0 && strcmp(mas[i], mas[i-1]) == 0){
            continue;
        }
        fprintf(res, "%s", mas[i]);
    }
    printf("%d\n", n);
    //sort----------------------------------------------

    //repsort-------------------------------------------

    // rap

    for (int sorted = 0; sorted < repn; sorted++) {
        for (int i = 0; i < repn - sorted - 1; i++) {
            if (sravnenie_rep(repmas[i], repmas[i + 1]) > 0) {
                swap_ptr(repmas + i, repmas + i + 1);
            }
        }
    }
    for (int i = 0; i < repn; i++) {
        //
        //printf("%d\n", i);
        //printf("%s", mas[i]);
        /////if (i > 0 && strcmp(repmas[i], repmas[i-1]) == 0){
        /////    continue;
        /////}
        fprintf(repres, "%s", repmas[i]);
    }
    printf("%d\n", n);
    
    //repsort-------------------------------------------

    
    
    return 0;
}

int sravnenie_rep(char* str1, char* str2) {
    int ind1 = 0;
    int ind2 = 0;

    while (*(str1 + ind1) != '\0')
        ind1++;
    while (*(str2 + ind2) != '\0')
        ind2++;
    
    while ((!isalpha(str1[ind1]) || !isalpha(str2[ind2])) || (str1[ind1] == str2[ind2])) {
        if ((!isalpha(str1[ind1]) || !isalpha(str2[ind2]))) {
            if (!isalpha(str1[ind1])) {
                ind1--;
            } else {
                ind2--;
            }
            continue;
        }
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
        return *(str1 + ind1) - *(str2 + ind2);
    }
    */
   return 0;
}