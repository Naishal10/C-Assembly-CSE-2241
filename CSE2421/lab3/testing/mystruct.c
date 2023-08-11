#include <stdio.h>
#include "mystruct.h"

void printStruct(struct MyStruct instance) {
    printf("ID: %d\n", instance.id);
    printf("Name: %s\n", instance.name);
}
