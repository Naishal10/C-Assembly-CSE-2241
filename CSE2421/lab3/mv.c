/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


void mv(struct Directory *currentDirectory,const char *sourcePath, const char *destinationPath) {
    struct File *destinationFile = findFile(currentDirectory, destinationPath);    
    struct Directory *destinationDirectory = findDirectory(currentDirectory, destinationPath);
    struct File *sourceFile = findFile(currentDirectory, sourcePath);
    struct Directory *sourceDirectory = findDirectory(currentDirectory, sourcePath);

    
    if (sourceFile == NULL && sourceDirectory == NULL) {
        printf("Source file or directory '%s' not found.\n", sourcePath);
        return;
    }

    if (destinationFile != NULL) {
        printf("File '%s' already exists.\n", destinationPath);
        return;
    }

    if (strcmp(sourcePath, destinationPath) == 0) {
        printf("Source and destination paths are the same.\n");
        return;
    }

    if(sourceFile != NULL && destinationDirectory != NULL) {
	destinationFile = file(sourceFile->name, sourceFile->content);
        addFileToDirectory(destinationDirectory, destinationFile);
        rm(currentDirectory, sourceFile);
        printf("File '%p' moved or renamed to '%s'.\n", sourceFile->name, destinationPath);

    }else if (sourceFile != NULL && destinationFile == NULL) {
        destinationFile = file(destinationPath, sourceFile->content);
        addFileToDirectory(currentDirectory, destinationFile);
        rm(currentDirectory, sourceFile);
        printf("File '%p' renamed to '%s'.\n", sourceFile->name, destinationPath);
    }
    else if (sourceDirectory != NULL && destinationDirectory == NULL) {
        destinationDirectory = mkdir(destinationPath, currentDirectory);
        copyDirectoryContents(sourceDirectory, destinationDirectory);
        addDirectoryToDirectory(currentDirectory, destinationDirectory);
        rmdir(currentDirectory, sourceDirectory);
        printf("Directory '%s' moved or renamed to '%s'.\n", sourceDirectory->name, destinationPath);
    }else if(sourceDirectory != NULL && destinationDirectory != NULL) {
        addDirectoryToDirectory(destinationDirectory,sourceDirectory);
        rmdir(currentDirectory, sourceDirectory);
        printf("Directory '%s' moved to '%s'.\n", sourceDirectory->name, destinationPath);
    }
}

