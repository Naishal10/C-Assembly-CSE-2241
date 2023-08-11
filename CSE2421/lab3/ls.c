/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include "lab3headers.h"

void ls(struct Directory *directory) {

    int i;   

    printf("Contents of directory '%s':\n", directory->name);
       
    for ( i = 0; i < directory->fileCount; i++) {
        printf("File: %s\n", directory->files[i]->name);
    }

    for ( i = 0; i < directory->directoryCount; i++) {
        printf("Directory: %s\n", directory->subdirectories[i]->name);
    }
}

