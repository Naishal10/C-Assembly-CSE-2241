/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void cp(struct Directory *currentDirectory, const char *source, const char *destinationPath){

    struct File *sourceFile = findFile(currentDirectory, source);
    struct Directory *sourceDirectory = findDirectory(currentDirectory, source);

    if (sourceFile == NULL && sourceDirectory == NULL) {
        printf("Source file or directory '%s' not found.\n", source);
        return;
    }
    if (findFile(currentDirectory, destinationPath) != NULL || findDirectory(currentDirectory, destinationPath) != NULL) {
        printf("Destination path '%s' already exists.\n", destinationPath);
        return;
    }
    if (strcmp(source, destinationPath) == 0) {
        printf("Source and destination paths cannot be the same.\n");
        return;
    }
    if (sourceFile != NULL) {
        
        struct File *destinationFile = file(sourceFile->name, sourceFile->content);
        addFileToDirectory(currentDirectory, destinationFile);
        printf("File '%s' copied to '%s'.\n", sourceFile->name, destinationPath);
    }
    else if (sourceDirectory != NULL) {
       
        struct Directory *destinationDirectory = mkdir(sourceDirectory->name, currentDirectory);
        copyDirectoryContents(sourceDirectory, destinationDirectory);
        addDirectoryToDirectory(currentDirectory, destinationDirectory);
        printf("Directory '%s' copied to '%s'.\n", sourceDirectory->name, destinationPath);
    }
   
}
