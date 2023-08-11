/*Naishal Patel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "lab3headers.h"

void cFiles(const char *directoryPath, struct Directory *rootDirectory) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directoryPath);
    if (dir == NULL) {
        printf("Error: Unable to open directory.\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {

	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        addFileToDirectory(rootDirectory, file(entry->d_name, "Dummy content"));
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {

   struct Directory *rootDirectory = mkdir("root", NULL);
   struct Directory *currentDirectory = rootDirectory;   
   char cmmd[300];
   char cmd[5];
   char arg1[MAX_NAME_LENGTH];
   char arg2[MAX_CONTENT_LENGTH];

   if (argc > 1) {
      cFiles(argv[1], rootDirectory);
   }

    while (1) {

        /*if (!processCmd( currentDirectory)) { break; }*/

        printf("Enter the command OR Enter 'help' for manual > ");
        scanf("%s", cmd);
/*        printf("Enter the first file name > ");
        scanf("%s", arg1);
        printf("Enter the next file name or content > ");
        scanf("%s", arg2);*/
	    
        if (strcmp(cmd, "cd") == 0) {
           scanf("%s", arg1);
             currentDirectory = cd(currentDirectory, arg1);
        }   
        else if (strcmp(cmd, "ls") == 0) {
            ls(currentDirectory);
        }   
        else if (strcmp(cmd, "pwd") == 0) {
            pwd(currentDirectory);
        }   
        else if (strcmp(cmd, "cat") == 0) {
	    scanf("%s", arg1);
            cat(currentDirectory, arg1);
        }   
        else if (strcmp(cmd, "cp") == 0) {
	    scanf("%s %s", arg1,arg2);
            cp(currentDirectory, arg1, arg2);
        }   
        else if (strcmp(cmd, "mv") == 0) {
	    scanf("%s %s", arg1,arg2);
            mv(currentDirectory, arg1, arg2);
        }   
        else if (strcmp(cmd, "rm") == 0) {
	    scanf("%s", arg1);
            rm(currentDirectory, findFile(currentDirectory,arg1) );
        }   
        else if (strcmp(cmd, "mkdir") == 0) {
	    scanf("%s", arg1);
            addDirectoryToDirectory(currentDirectory , mkdir(arg1,currentDirectory));
        }   
        else if (strcmp(cmd, "rmdir") == 0) {
	    scanf("%s", arg1);
            rmdir(currentDirectory, findDirectory(currentDirectory, arg1));
        }   
        else if (strcmp(cmd, "file") == 0) {
	    scanf("%s", arg1);
            addFileToDirectory(currentDirectory,mkfile(arg1));
        }   
        else if (strcmp(cmd, "help") == 0) {
            help();
        }
        else if (strcmp(cmd, "dirprint") == 0) {
            dirprint(currentDirectory);
        }
        else if (strcmp(cmd, "search") == 0) {
	    scanf("%s", arg1);
            search(currentDirectory,arg1);
        }
        else if (strcmp(cmd, "fedit") == 0) {
	    scanf("%s", arg1);
            fedit(currentDirectory,arg1);
        }
        else if (strcmp(cmd, "blank") == 0) {
	    scanf("%s", arg1);
            blank(currentDirectory,arg1);
        }
        else if (strcmp(cmd, "quit") == 0) {
            break;
        }   
        else {
            printf("Invalid command. Type 'help' to see the list of available commands.\n");
        }   

    }

    freeDirectory(rootDirectory);
    
    return 0;
}
