/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3headers.h"

struct File *file(const char *fileName, const char *content) {
    struct File *newFile = malloc(sizeof(struct File));
    strncpy(newFile->name, fileName, MAX_NAME_LENGTH);
    strncpy(newFile->content, content, MAX_CONTENT_LENGTH);

    return newFile;
}
