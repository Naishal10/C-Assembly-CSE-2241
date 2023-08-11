
/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"




void search(struct Directory *currentDirectory, const char *searchTerm) {
    int i;

    printf("Search results for '%s':\n", searchTerm);


    for (i = 0; i < currentDirectory->fileCount; i++) {
        if (strstr(currentDirectory->files[i]->name, searchTerm) != NULL) {
            printf("%s\n", currentDirectory->files[i]->name);
        }
    }
    for (i = 0; i < currentDirectory->directoryCount; i++) {
        search(currentDirectory->subdirectories[i], searchTerm);
    }
}
