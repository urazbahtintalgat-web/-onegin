#include "onegin_reader.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

int onegin_reader(FILE* text, char*** mas, int* maxlen) {
    printf("onegin reader started\n");
    char* buffer = NULL;
    size_t len = 0;
    int read = 0;
    int i = 0;

    while ((read = my_getline(&buffer, &len, text)) != -1) {
        //printf("while started\n");
        if (i >= *maxlen) {
            printf("expention\n");
            printf("%d -> ", *maxlen);
            *maxlen *= 2;
            printf("%d\n", *maxlen);
            char** new_mas = (char **) realloc(*mas, *maxlen * sizeof(char*));
            *mas = new_mas;
            //printf("%d\n", maxlen);
        }
        char* startind = buffer;
        //printf("%d\n", strlen(buffer));
        if (read <= 1){
            continue;
        }

        while ((*startind < 'A') || (*startind > 'Z' && *startind < 'a') || (*startind > 'z'))
            startind++;

        *(*mas + i++) = startind;
        buffer = NULL;
        //printf("%s\n%d\n", *(mas + i - 1), i - 1);
    }
    //char ch;
    //scanf("%c", ch);
    //printf("%d\n\n\n\n\n", i);
    return i;
}
