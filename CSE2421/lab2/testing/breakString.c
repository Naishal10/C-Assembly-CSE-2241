#include <stdio.h>
void printBinaryChar(unsigned char character) {
    int i;
    for (i = 7; i >= 0; i--) {
        if ((character >> i) & 1)
            putchar('1');
        else
            putchar('0');
    }
}

int main() {
    FILE *inputFile;
    char inputFileName[100];
    int i;
    int ch;
    int counter;
   unsigned  char string[8];    
   unsigned char left; 
   unsigned char right; 
   unsigned char center;
 
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    counter = 0;
    while ((ch = fgetc(inputFile)) != EOF) {
        int bits[8];

	if(counter == 7) {
    	       
	   for(i = 0; i < 8; i++) {
              bits[i] = (ch >> i) & 1;
           }
 	   for(i = 0; i < 7; i++) {
  
		left = string[i] >> (7-i);

		left = left << (8-i);

		right = string[i] << (i+1);

		right = right >> (i+1);
				
		center = (bits[i] << (7-i));

	 	string[i] = (left | right) | center ;
		
		printBinaryChar(string[i]);
		printf("\n");
           }

	   printf("%s",string);
     	   for(i = 0; i < 8; i++) {
              string[i] = ' ';
           }
           counter = 0;
	}
        
	string[counter] = ch;
	counter += 1;
    }

    if((counter < 7) && (counter > 0)) {
      printf("%s",string);
    }
    
    

    fclose(inputFile);

    return 0;
}
