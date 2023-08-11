/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void freeDirectory(struct Directory* directory) {
    int i;    
    for (i = 0; i < directory->fileCount; i++) {
        free(directory->files[i]->name);
        free(directory->files[i]->content);
        free(directory->files[i]);
    }

   
    for (i = 0; i < directory->directoryCount; i++) {
        freeDirectory(directory->subdirectories[i]);
        free(directory->subdirectories[i]);
    }

    
    free(directory->name);
    free(directory->files);
    free(directory->subdirectories);
    free(directory);
}
