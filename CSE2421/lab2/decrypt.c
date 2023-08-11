#include <stdio.h>
#include "constants.h"

int extractBit(int pos,unsigned char cha) {
  unsigned char left = cha >> ((CHUNK-1)-pos);
        left = left << (CHUNK-1);
   if(left > 0) {
        return 1;
   }else {
        return 0;
   }
}



int main() {
    int i;
    int ch;
    int counter;
   unsigned char string[CHUNK-1];
    int bits[CHUNK];
   unsigned char left;
   unsigned char right;
   unsigned char center;
   unsigned char newch = 0;

    bits[0]=0;
    counter = 0;
    while ((ch = getchar()) != EOF) {

        string[counter] = ch;
        bits[(CHUNK-1)-counter] = extractBit(counter,string[counter]);
        counter += 1;

        if(counter == (CHUNK-1)) {
           for(i = 0; i < (CHUNK-1); i++) {
                left = string[i] >> (CHUNK-i);

                left = left << (CHUNK-1-i);

                right = string[i] << (i+1);

                right = right >> (i+1);

                string[i] = left | right;
                putchar(string[i]);

           }
           for (i = 0; i < CHUNK; i++) {

                newch = newch | (bits[i] << ((CHUNK-1) - i));

           }
           printf("%c", newch);
           newch = 0;
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
