/* all of your C code should have your name at the top in a comment */

/* all of your C code should have a brief description comment above every
 * function that give the one job of that function.
 */

/* I'm using an interesting method of indentation here.
 * Function names have no indentation.
 * The first level of indentation is 8 characters, which is a tab for me.
 * All of the next levels of indentation are 4 characters more than the
 * last level.
 * This 0-8-4 style of indentation makes it easy to locate functions and
 * easy to read blocks.
 * I do not require you to use this form of indentation!
 * I do, however, require you to be consistent.
 */

#include <stdio.h>
#include <stdlib.h>

/* this function divides two numbers and returns the result */
int divide( int x, int y){
	return (x/y);
}

/* making a pyramid out of the factors of limit
 * so, bot / 1 should appear limit number of times,
 * bot / 2 should appear half as many times, and so on 
 */
void art(int bot){
	int i, j;
	for(i=bot; i>0; i--){
	    int num = divide(bot,i);
	    for(j=0; j<num; j++){
	        printf("%d ", num);
	    }
	    printf("\n");
	}
}

/* in C we often delegate tasks to other functions */
int main(){
	art(10);
	return 0;
}
