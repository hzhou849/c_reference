/* 2-16 Generic Pointers
*
* - Generic pointers are useful if you want to reuse a pointer to handle multiple data types
*/

#include <stdio.h>

#define LENGTH 3

int data[LENGTH];		// some integers
char* words[LENGTH];	// some strings

int main (int argc, char **argv) 
{
	void *gp;	// a generic pointer

	printf("Generic pointer example\n");

	//initialize our integer array
	for (int i=0; i<LENGTH; i++) {
		data[i] = i;
	}
	for (int i=0; i<LENGTH; i++) {
		printf("%d\n", data[i]);
	}

	// initialize our string array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";

	for (int i=0; i<LENGTH; i++) {
		printf("%s\n", words[i]);
	}

	gp=data;			// sets the generic pointer to array address since this is address only, no cast needed yet
	printf("\ndata array address is %p\n", gp);

	/* a cast is now needed to let the compiler know what sort of thing is 
	* is being pointed to by
	*/
	printf("item pointed to by gp is %d; %p\n", *(int*)gp, gp);
	// the cast tells the compiler what the address type is so we can do address arthimatic

	gp = (int*)gp +1;
	printf("item pointed to by gp is now %d;  %p\n", *(int*)gp, gp);

	// Strings
	gp = words;
	printf("\nwords array address is %p\n", gp);
	printf("item is pointed to by gp is %s; %p\n",*(char **)gp, gp);
	
	gp = (char**)gp +1;
	printf("item pionted to by gp is now %s; %p\n", *(char**)gp, gp);

	return 0;
}

