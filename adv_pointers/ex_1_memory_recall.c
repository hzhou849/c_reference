/* 
 * A memory example that utilizes malloc, free, addressing concepts
 * 
 * repeat this again for larger data types.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 8

char* mem_block[LENGTH];		// represent a block of memory to store data

int main (int argc, char **argb)
{
	void *gen_ptr;		// a generic pointer
	char* s;

	printf("Memory example.\n");

	// Allocate memory typed in long format
	// shorthand: (char*)malloc(6)  
	s = (char*) malloc(LENGTH * sizeof(char));
	
	// check that allocation if not NULL
	if (s == NULL) {
		printf("malloc failed!\n");
		exit(0);
	}
	
	strncpy(s, "abcdefgh", LENGTH) ;
	printf("s is %s\n", s);
	printf("address of s is: %p\n", s);
	
	for(int i=0; i<LENGTH; i++) {
		printf("s[%d]: %c; address %p\n", i, s[i], &s[i]);
	}

	// print back the memory address
	int *add_ptr;
	add_ptr=&s[1];
	printf("add_ptr: %p; value: %c", add_ptr, *add_ptr);

	free(s);


}