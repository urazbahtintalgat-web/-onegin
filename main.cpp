#include <stdio.h>
#include <string.h>

#include "my_string.h"

void swap_str(char* str1, char* str2) {
    for (int i = 0; i < 100; i++) {
        str1[i] ^= str2[i];
        str2[i] ^= str1[i];
        str1[i] ^= str2[i];
    }
}

int main(){
    FILE* test = fopen("text.txt", "r");
    char mas[1000][100];
    int n = 0;
    while (my_fgets(mas[n++], 100, test) != NULL && n < 1000)
        ;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n-j; i++){
            if (strcmp(mas[i - 1], mas[i]) > 0) {
                swap_str(mas[i - 1], mas[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s", mas[i]);
    }
    return 1;
}
