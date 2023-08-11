#include <stdio.h>
#include "mystruct.h"

int main() {
    struct MyStruct instance;

    instance.id = 1;
    snprintf(instance.name, sizeof(instance.name), "John");

    printStruct(instance);

    return 0;
}
