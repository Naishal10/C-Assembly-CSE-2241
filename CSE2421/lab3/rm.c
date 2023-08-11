/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include "lab3headers.h"

void rm(struct Directory* directory,struct File* file) {
    int i;
    int j;
    for (i = 0; i < directory->fileCount; i++) {
        if (directory->files[i] == file) {
           
            for (j = i; j < directory->fileCount - 1; j++) {
                directory->files[j] = directory->files[j + 1];
            }
            directory->fileCount--;
            free(file);
            return;
        }
    }
    printf("File not found in the directory.\n");
}
