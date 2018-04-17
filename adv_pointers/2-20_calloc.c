/*
 * 2-20 Calloc
 * 
 * - Clears memory on iniitalization with nulls.
 * - 2 arguments
 * 	 	i) number of elements in the array.
 * 	   ii) size of each element.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	char* s;
	int i;
	int* p;

	// use malloc first to allocate some memory to see
	// what is inside the uninitialized mem.
	printf("MALLOC:\n");
	s = (char*)malloc(6 * sizeof(char));
	for (i=0; i<6; i++) {
		// s[i]='s';
		printf("s[%d]=%d\n", i, s[i]);
	}
	
	// free the allocated memory
	// free(s);
	printf("\n");


	// Using calloc
	printf("CALLOC:\n");
	s = (char*)calloc(6, sizeof(char));
	for (i=0; i<6; i++) {
		printf("s[%d] =%d\n", i, s[i]);
	}
	free(s);
	printf("\n");

	// using calloc allocate 6ints (int is 4bytes each) or 24bytes
	p = (int*)calloc(6, sizeof(int));
	for (i=0; i<6; i++) {
		printf("p[%d]=%d\n", i, p[i]);
	}
	free(p);

	return 0;
}
