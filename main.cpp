#include <stdio.h>
#include <string.h>

#include "my_string.h"
#include "onegin_reader.h"

#define MAXSTRINGS 1000

void swap_str(char* str1, char* str2) {
    for (int i = 0; i < 100; i++) {
        str1[i] ^= str2[i];
        str2[i] ^= str1[i];
        str1[i] ^= str2[i];
    }
}



int main(){
    FILE* text = fopen("text.txt", "r");
    char* mas[MAXSTRINGS];
    int n = onegin_reader(text, mas, MAXSTRINGS);
    //printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        //printf("%d\n", i);
        printf("%s", mas[i]);
    }
    
    return 1;
}
