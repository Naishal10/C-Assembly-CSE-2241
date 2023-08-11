#include <stdio.h>
#include <stdlib.h>

void processCommand(const char *command, const char *file1, const char *file2) {
    printf("Command: %s\n", command);
    printf("File 1: %s\n", file1);
    printf("File 2: %s\n", file2);
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    if (fp1 == NULL) {
        printf("File 1 does not exist.\n");
        return;
    }

    if (fp2 == NULL) {
        printf("File 2 does not exist.\n");
        return;
    }

    printf("Both files exist.\n");

    fclose(fp1);
    fclose(fp2);
}

int main() {
    char command[50];
    char file1[50];
    char file2[50];

    printf("Enter the command and file names (separated by spaces): ");
    scanf("%49s %49s %49s", command, file1, file2);
	if(file1 == NULL){
		file1 = '';
	}
	if(file2 == NULL){
                file2 = '';
        }
    processCommand(command, file1, file2);

    return 0;
}
