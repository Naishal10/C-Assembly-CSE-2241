/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include "lab3headers.h"

void pwd(struct Directory *currentDirectory) {

    struct Directory *tempDirectory; 
    printf("Current working directory: ");

    tempDirectory = currentDirectory;
    while (tempDirectory != NULL) {
        printf("/%s", tempDirectory->name);
        tempDirectory = tempDirectory->parent;
    }

    printf("\n");
}
