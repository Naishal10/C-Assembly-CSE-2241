/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"


struct File *findFile(struct Directory *directory, const char* fileName) {
    int i;
    for (i = 0; i < directory->fileCount; i++) {
        if (strcmp(directory->files[i]->name, fileName) == 0) {
           
            return directory->files[i];
        }
    }

    
    return NULL;
}

struct Directory *findDirectory(struct Directory* currentDirectory, const char* directoryName) {
    int i;
    if (strcmp(currentDirectory->name, directoryName) == 0) {
        return currentDirectory;
    }

    for ( i = 0; i < currentDirectory->directoryCount; i++) {
        struct Directory *subdirectory = currentDirectory->subdirectories[i];
        struct Directory *foundDirectory = findDirectory(subdirectory, directoryName);
        if (foundDirectory != NULL) {
            return foundDirectory;
        }
    }

    return NULL;
}


void addFileToDirectory(struct Directory *directory,struct File* file) {
    if ((directory->fileCount + directory->directoryCount) < 64) {
        directory->files[directory->fileCount] = file;
        directory->fileCount++;
    } else {
        printf("Maximum limit reached in the directory.\n");
    }
}

void addDirectoryToDirectory(struct Directory *directory,struct Directory *subdirectory) {
     
    if ((directory->fileCount + directory->directoryCount) < 64) {
        directory->subdirectories[directory->directoryCount] = subdirectory;
        directory->directoryCount++;
    } else {
        printf("Maximum limit reached in the directory.\n");
    }
}

void copyDirectoryContents(struct Directory *sourceDirectory,struct Directory *destinationDirectory) {
    int i; 
    for ( i = 0; i < sourceDirectory->fileCount; i++) {
        struct File *sourceFile = sourceDirectory->files[i];
        struct File *destinationFile = file(sourceFile->name, sourceFile->content);
        addFileToDirectory(destinationDirectory, destinationFile);
    }

   
    for ( i = 0; i < sourceDirectory->directoryCount; i++) {
        struct Directory *sourceSubdirectory = sourceDirectory->subdirectories[i];
        struct Directory *destinationSubdirectory = mkdir(sourceSubdirectory->name, destinationDirectory);
        copyDirectoryContents(sourceSubdirectory, destinationSubdirectory);
        addDirectoryToDirectory(destinationDirectory, destinationSubdirectory);
    }
}





