/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

struct Directory *cd(struct Directory *currentDirectory, const char *directoryName) {
    
    if (strcmp(directoryName, "..") == 0) {
        
        if (currentDirectory->parent == NULL) {
            printf("Already at the root directory.\n");
            return currentDirectory;
        }
        else {
            return currentDirectory->parent;
        }
    }
    else {
        
        int i;
        for (i = 0; i < currentDirectory->directoryCount; i++) {
            if (strcmp(directoryName, currentDirectory->subdirectories[i]->name) == 0) {
                return currentDirectory->subdirectories[i];
            }
        }
        
        printf("Directory '%s' not found.\n", directoryName);
        return currentDirectory;
    }
}
