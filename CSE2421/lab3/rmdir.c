/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include "lab3headers.h"


void rmdir(struct Directory* currentDirectory,struct Directory* directoryToRemove) {
    int i;
    int j;    
    for ( i = 0; i < currentDirectory->directoryCount; i++) {
        if (currentDirectory->subdirectories[i] == directoryToRemove) {
            
            for (j = i; j < currentDirectory->directoryCount - 1; j++) {
                currentDirectory->subdirectories[j] = currentDirectory->subdirectories[j + 1];
            }
            currentDirectory->directoryCount--;
            return;
        }
    }

   
    printf("Directory not found in the current directory.\n");
}

