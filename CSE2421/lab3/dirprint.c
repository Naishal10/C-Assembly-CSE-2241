
/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void printDirectories(struct Directory *currentDirectory, int numChildDirectories, int indentLevel ) {

     int i,j;

    if (currentDirectory == NULL || numChildDirectories < 0) {
        return;
    }

    printf("(dir)%s\n", currentDirectory->name);

    for (i = 0; i < currentDirectory->fileCount; i++) {
        for (j = 0; j < ((indentLevel) * 4)+2; j++) {
                printf(" ");
        }
        printf("(file)%s\n", currentDirectory->files[i]->name);
    }


    if (numChildDirectories > 0) {
        for (i = 0; i < currentDirectory->directoryCount; i++) {

            for (j = 0; j < ((indentLevel) * 4)+2; j++) {
                printf(" ");
            }
            printDirectories(currentDirectory->subdirectories[i], numChildDirectories - 1,indentLevel + 1);
        }
    }
}

void dirprint(struct Directory *currentDirectory) {

    int i, j;
    int numParents = 0;
    struct Directory *temp = currentDirectory;

    while (temp->parent != NULL) {
        temp = temp->parent;
        numParents++;
    }

    printDirectories(temp,numParents,0);

}

