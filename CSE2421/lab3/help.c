/*Naishal Patel*/
#include <stdio.h>
#include "lab3headers.h"

void help() {
    printf("Available commands:\n");
    printf("cd <directory>      Change directory to the specified directory\n");
    printf("ls                  List the contents of the current directory\n");
    printf("pwd                 Print the current working directory\n");
    printf("cat <file>          Display the contents of the specified file\n");
    printf("cp <source> <dest>  Copy a file or directory from source to destination\n");
    printf("mv <source> <dest>  Move or rename a file or directory from source to destination\n");
    printf("rm <path>           Remove a file or directory at the specified path\n");
    printf("mkdir <name>        Create a new directory with the specified name\n");
    printf("rmdir <name>        Remove an empty directory with the specified name\n");
    printf("file <name>         Create a new file with the specified name and enter its contents\n"); 
    printf("fedit <name>        Change the contents of the existing file\n");
    printf("blank <name>        Clears the contents of existing file\n");
    printf("search <name>       Search to see if the file exists in the system\n");
    printf("dirprint <name>     Print all the directories and files starting from root to current directory\n");
    printf("help                Display this help message\n");
}
