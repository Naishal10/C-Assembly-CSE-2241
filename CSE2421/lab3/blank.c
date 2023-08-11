
/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void blank(struct Directory *currentDirectory, const char *fileName) {
    int i;
    struct File *targetFile = findFile(currentDirectory, fileName);

    if (targetFile == NULL) {
        printf("File '%s' not found.\n", fileName);
        return;
    }

    for (i = 0; i < MAX_CONTENT_LENGTH; i++) {
        targetFile->content[i] = '\0';
    }

    printf("Content of file '%s' cleared.\n", fileName);
}
