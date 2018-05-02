#include <stdio.h>

#define LENGTH 3

int data[LENGTH];

int main (int argc, char **argv) {
	int *pi;		// pointer to int
	int **ppi; 		// pointer to a pointer to an int.

	printf("Multiple indirection:\n");

	//initialize the array
	for (int i=0; i<LENGTH; i ++) {
		data[i] = i;
		printf("%d\n", data[i]);
	}

	pi = data;			// set the pointer to an integer to the start of the data array
	ppi = &pi;			// and set the pointer to a pointer to pi itself

	for (int i = 0; i<LENGTH; i++) {
		printf("Iteration[%d] array 'data[]' address: %p\n", i, data);
		printf("&data: %p\n", &data);
		printf("*pi: %p\n", *pi);
		printf("*ppi: %p\n", *ppi);
		printf("double indirection of **ppi: %d\n", **ppi);
		printf("address &pi: %p, value of pi (ppi): %p\n", &pi, ppi);
		printf("address &ppi: %p, **ppi: %p\n", &ppi, **ppi);
		printf("ppi: %p\n", ppi);
		printf("pi: %p\n\n", pi);

		pi +=1;
	}


}