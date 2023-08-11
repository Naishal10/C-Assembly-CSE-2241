

/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void cpdir(struct Directory *currentDirectory, struct Directory *sourceDirectory,struct Directory *destinationDirectory) {
    struct Directory *sourceDir = findDirectory(currentDirectory, sourcePath);
    struct Directory *destinationDir = findDirectory(currentDirectory, destinationPath);
 
    if (sourceDir == NULL) {
        printf("Source directory '%s' not found.\n", sourcePath);
        return;
    }
    if (destinationDir == NULL) {
        printf("Destination directory '%s' not found.\n", destinationPath);
        return;
    }
    if (findDirectory(destinationDirectory, sourceDirectory->name) != NULL) {
        printf("Destination directory '%s' already exists.\n", sourceDirectory->name);
        return;
    }


}

