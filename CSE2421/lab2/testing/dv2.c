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
  
int extractBit(int pos,unsigned char cha) {
  // unsigned char mask = cha >> pos;
  // return (mask & 1) ;
  unsigned char left = cha >> (7-pos);
	left = left << 7;
   if(left > 0) {
	return 1;
   }else {
	return 0;
   }
}

unsigned char flipBits(unsigned char ch) {
    unsigned char flippedChar = 0;

    for (int i = 0; i < 8; i++) {
	 flippedChar <<= 1;  
	flippedChar |= (ch & 1);
	ch >>= 1;  
    }
    return flippedChar;
}


int main() {
    int i;
    int ch;
    int counter;
   unsigned char string[7];    
    int bits[8];
    int flipped_bits[8];
   unsigned char left;
   unsigned char right;
   unsigned char center; 
   unsigned char newch = 0; 

    bits[0]=0;
    counter = 0;
    while ((ch = getchar()) != EOF) {
	
	string[counter] = ch;
        bits[7-counter] = extractBit(counter,string[counter]);
//	printf("%i",bits[counter]);
//	printf("\n");
	counter += 1;

	if(counter == 7) {
	   for(i = 0; i < 7; i++) {
//  		printBinaryChar(string[i]);
//		printf("\n");
                left = string[i] >> (8-i);

                left = left << (7-i);

                right = string[i] << (i+1);

                right = right >> (i+1);

		string[i] = left | right;
		putchar(string[i]);
           
	   }
 	   for (int i = 0; i < 8; i++) {
        	newch |= (bits[i] << (7 - i));
           }
	   printf("%c", newch);

	 //  printf("%c", flipBits(newch)); 
	// putchar((int)flipBits(newch));
//      	   printBinaryChar(flipBits(newch));	
//printf("\n");
	
	   counter = 0;
	}
        
    }
    
    if (counter > 0) {
           for(i=0;i<counter;i++){
              putchar(string[i]);
           }
    }
    

    return 0;
}
