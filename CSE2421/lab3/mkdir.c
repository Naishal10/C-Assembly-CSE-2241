/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

struct Directory *mkdir(const char *name,struct Directory *parent) {
    struct Directory *directory = (struct Directory*)malloc(sizeof(struct Directory));
    strncpy(directory->name, name, MAX_NAME_LENGTH);
    directory->parent = parent;
    directory->fileCount = 0;
    directory->directoryCount = 0;
    return directory;
}

