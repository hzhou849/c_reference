/* 2-15 indirection command line arguments 
* NOTE: main function since arrays are pointers therefore it is similar
* **argv functionally equiv to *argv[]
*/


#include <stdio.h>

int main (int argc, char **argv) {
	int i;

	//(1) iterate over array of args
	for (int i=0; i<argc; i++) {
		printf("arg %d is %s\n", i, argv[i]); //prints arg at index i
	}

	printf("\n\n");

	// 2) dereference each string arg (*argv) via pointer to pointer
	// to the start of the array of args (**argv)

	for (i=0; i<argc; i++) {
		printf("arg %d is %s\n", i, *argv); // prints arg pointed to by arg
		argv += 1;
	}

	return 0;


}