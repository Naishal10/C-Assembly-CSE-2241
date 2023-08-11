/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

void writeFileContent(struct File* file) {
    printf("Enter the content of the file '%s':\n", file->name);
    scanf(" %[^\n]s", file->content);
}

struct File *mkfile(const char *fileName) {

    struct File* newFile = (struct File*)malloc(sizeof(struct File));
    strncpy(newFile->name, fileName, sizeof(newFile->name));
    newFile->name[sizeof(newFile->name) - 1] = '\0';
    writeFileContent(newFile);
    return newFile;
}


