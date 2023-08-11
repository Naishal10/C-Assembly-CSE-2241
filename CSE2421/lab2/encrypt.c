#include "constants.h"
#include <stdio.h> 

int main() {
    int i;
    int ch;
    int counter;
   unsigned char string[8];
   unsigned char left;
   unsigned char right;
   unsigned char center;


    counter = 0;
    while ((ch = getchar()) != EOF) {
        int bits[CHUNK];

        string[counter] = ch;
        counter += 1;

        if(counter == CHUNK) {

           for(i = 0; i < CHUNK; i++) {
              bits[i] = (ch >> i) & 1;
           }
           for(i = 0; i < CHUNK-1; i++) {

                left = string[i] >> ((CHUNK-1)-i);

                left = left << (CHUNK-i);

                right = string[i] << (i+1);

                right = right >> (i+1);

                center = (bits[i] << ((CHUNK-1)-i));

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

