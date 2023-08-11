/*Naishal Patel*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

void cat(struct Directory *currentDirectory, const char *filename) {


    int i;
    struct File *file = NULL;
    for (i = 0; i < currentDirectory->fileCount; i++) {
       if (strcmp(filename, currentDirectory->files[i]->name) == 0) {
            file = currentDirectory->files[i];
            break;
        }
    }

    if (file != NULL) {
        printf("Contents of file '%s':\n", file->name);
        printf("%s\n", file->content);
    } else {
        printf("File '%s' not found\n", filename);
    }
}
