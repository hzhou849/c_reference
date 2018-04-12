#include <stdio.h>

#define LENGTH 5

int data [LENGTH];

int main (int argc, char **argv)
{
	int *pi;		// pointer interger
	int **ppi;		// pointer to pointer integer

	printf("muliple indirection example\n");

	// intialize our integer array
	for (int i=0; i<LENGTH; i++) {
		data[i] = i;
		printf("%d\n", data[i]);
	}

	/*Simple pointer to pointer integer */

	pi=data;	// set the pointer to an integer to the start the data array
	ppi = &pi; 	// and set the pointer to a pointer to pi itself

	for (int i=0; i<LENGTH; i++) {
		printf("\nLoop[%d] array address is %p\n", i, data);
		printf("item pointed to by pi is %d\n", *pi);
		printf("item pointed to by ppi is %p\n", *ppi);
		printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
		printf("The address of pi is %p and the value of pi (what it points to) is %p\n\n", &pi, ppi);

		pi += 1; // advance the pointer to point to the next element of the data array
	}
}

