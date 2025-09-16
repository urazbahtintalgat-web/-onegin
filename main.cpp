#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_string.h"
#include "onegin_reader.h"

int MAXSTRINGS = 1000;

void swap_str(char* str1, char* str2) {
    for (int i = 0; i < 100; i++) {
        str1[i] ^= str2[i];
        str2[i] ^= str1[i];
        str1[i] ^= str2[i];
    }
}

int sortlex(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

//int sortrep(const void* a, const void* b) {
//    const char* str1 = *(const char**)a;
//    const char* str2 = *(const char**)b;
//    return repstrcmp((char *) str1, (char *) str2);
//}

int main(){
    char** mas;
    mas = (char **) malloc(MAXSTRINGS * sizeof(char*));

    FILE* text = fopen("textonegin.txt", "r");
    FILE* res = fopen("result.txt", "w");
    //FILE* repres = fopen("represult.txt", "w");
    int n = onegin_reader(text, &mas, &MAXSTRINGS);



    qsort(mas, (size_t) n, sizeof(char*), sortlex);
    
    for (int i = 0; i < n; i++) {
        //printf("%d\n", i);
        //printf("%s", mas[i]);
        if (i > 0 && strcmp(mas[i], mas[i-1]) == 0){
            continue;
        }
        fprintf(res, "%s", mas[i]);
    }
    printf("%d\n", n);


    /*qsort(mas, (size_t) n, sizeof(char*), sortrep);

    for (int i = 0; i < n; i++) {
        //printf("%d\n", i);
        //printf("%s", mas[i]);
        if (i > 0 && strcmp(mas[i], mas[i-1]) == 0){
            continue;
        }
        fprintf(res, "%s", mas[i]);
    }
    printf("%d\n", n);*/



    
    
    return 0;
}
