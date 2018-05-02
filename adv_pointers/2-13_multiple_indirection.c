#include <stdio.h>

#define LENGTH 3

int data [LENGTH];

int main(int argc, char **argv) 
{
	int *pi;		// pointer integer
	int **ppi;		// pointer to pointer integer

	printf("multiple indirection example\n");

	//initialize our integer array
	for (int i=0; i<LENGTH; i++) {
			data[i] = i;
	}
	for (int i=0; i<LENGTH; i++) {
		printf("%d\n", data[i]);
	}

	/* Simple pointer to pointer interger */

	pi = data; // set the pointer to an integer to the start of the data array
	ppi = &pi; // and set the pointer to a pointer to pi itself

	for (int i=0; i < LENGTH; i++) {
		printf("\nLoop[%d] array address is %p\n", i, data);
		printf("item pointed to by pi is %d\n", *pi);
		printf("item pointed to by ppi is %p\n", *ppi);
		printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
		printf("The address of pi is %p and the value of pi (what it points to ) is %p\n\n", &pi, ppi);

		pi += 1; // advance the pointer to point to the next element of the data array
	}

	return 0;
}

// Output:
// multiple indirection example
// 0
// 1
// 2

// Loop[0] array address is 0x601050
// item pointed to by pi is 0
// item pointed to by ppi is 0x601050
// item pointed to by double indirection of ppi is 0

// The address of pi is 0x7ffdb93eae78 and the value of pi (what it points to ) is 0x7ffdb93eae78


// Loop[1] array address is 0x601050
// item pointed to by pi is 1
// item pointed to by ppi is 0x601054
// item pointed to by double indirection of ppi is 1

// The address of pi is 0x7ffdb93eae78 and the value of pi (what it points to ) is 0x7ffdb93eae78


// Loop[2] array address is 0x601050
// item pointed to by pi is 2
// item pointed to by ppi is 0x601058
// item pointed to by double indirection of ppi is 2

// The address of pi is 0x7ffdb93eae78 and the value of pi (what it points to ) is 0x7ffdb93eae78