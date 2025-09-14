#include "onegin_reader.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

int onegin_reader(FILE* text, char* mas[], int maxlen) {
    //printf("onegin reader +\n");
    char * buffer = NULL;
    size_t len = 0;
    int read = 0;

    int i = 0;
    while ((read = my_getline(&buffer, &len, text)) != -1) {
        //printf("while started\n");
        *(mas + i++) = buffer;
        buffer = NULL;
        //printf("%s\n%d\n", *(mas + i - 1), i - 1);
    }
    //printf("%d\n\n\n\n\n", i);
    return i;
}