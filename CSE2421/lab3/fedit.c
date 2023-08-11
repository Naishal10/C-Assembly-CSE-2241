

/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

void editContent(struct File* file) {
    printf("Enter the new content of the file '%s':\n", file->name);
    scanf(" %[^\n]s", file->content);
}


void fedit(struct Directory *currentDirectory, const char *fileName) {
    struct File *targetFile = findFile(currentDirectory, fileName);

    if (targetFile == NULL) {
        printf("File '%s' not found.\n", fileName);
        return;
    }
    
    editContent(targetFile);

}
