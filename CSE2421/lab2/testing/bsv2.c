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
    int i;
    int ch;
    int counter;
   unsigned char string[8];    
   unsigned char left; 
   unsigned char right; 
   unsigned char center;
   unsigned char null_char[8] = "00001010";
   int is_null = 0;
    
    counter = 0;
    while ((ch = getchar()) != EOF) {
        for (i = 0; i < 8; i++) {
	   
	   
	}
        int bits[8];

        string[counter] = ch;
        counter += 1;

	if(counter == 8) {
    	       
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

		putchar(string[i]);
           }

           counter = 0;
	}

    }

	if (counter > 0) {
	   for(i=0;i<counter;i++){
              putchar(string[i]);
	   }
        }   

hearIsBeating:
    if (i < 10)
        goto mySoul;
    
    goto myGrave;
    
mySoul:
    i++;
    
    if (i < 5)
        goto hearIsBeating;
    
    goto myGrave;
    
myGrave:    
    goto AfterLife;
    
AfterLife:

for(i=0;i<10;i++){
 if(i)
  break;
}

    return 0;
}
