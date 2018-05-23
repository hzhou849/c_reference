/* Struct Pointer
 * Memory alignment
 * 
 * Notation difference:
 * 	struct -> defrenence pointer
 * 	struct '.' to access the member
 * 
 * buffer_1: 0x23b0020 
 * buffer_2: 0x23b0024 
 * buffer_3: 0x23b0028
 * buffer_4 is 0x23b0030 = 244bytes 
 * 
 * //Syntax diffrence calloc vs malloc
 * // Allocate bytes =<datatypeSize>calloc <LENGTH(number of blocks), totalSize>
 * // (int*) malloc (sizeof(int) * 1000)
 * p = (STRUCT_BUFFER*)malloc(LENGTH, 24);
 * 
 * Example:
 * 	//both versions, malloc vs calloc
	// p = (STRUCT_BUFFER*)calloc(sizeof(STRUCT_BUFFER), LENGTH);
	p = (STRUCT_BUFFER *) malloc (sizeof(STRUCT_BUFFER) * LENGTH);
 * 
 * // Breakdown of one block struct.
 * address: | 0x23b0020-> 0x23b0024 | 0x23b0025-26-27-28 | 0x23b0029-0a-0b-0c-0d-0e-0f-30 | 31-38          |
 * size:    |          4bytes       |      4 bytes       |       8 bytes                  |   8bytes       |
 * 
 * 
 * Why use malloc for structs?
 * A struct can be allocated automatically, but you are using a pointer to struct which will not allocate space for the destination struct. So that's the reason you get segfault.

The reason your initialization is incorrect is that you are initializing struct members, not the struct itself. Also you are doing this in a wrong way.

There are 2 ways for initializing a struct :

1. Using stack allocated struct:

	struct example {
	  int foo;
	};
	int main() {
	  struct example e;
	  e.foo=1;
	}
2. Using heap allocated struct with help of malloc():

	struct example {
	  int foo;
	};
	int main() {
	  struct example *e=malloc(sizeof(struct example));
	  e->foo=1;
	}
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 4

typedef struct {
	int buffer_1;		//4 bytes
	int buffer_2;		//4 bytes
	double buffer_3; 			//8 bytes
	long long int buffer_4;	//8 bytes
} STRUCT_BUFFER;


int main (int argc, char **argv) {
	STRUCT_BUFFER *p, *q;
	void* v;

	//size is 32bytes if struct variable declaration is not declared in order.
	printf("size of STRUCT_BUFFER = %d\n", sizeof(STRUCT_BUFFER)); 

	//allocates 2
	// p = (STRUCT_BUFFER*)calloc(sizeof(STRUCT_BUFFER), LENGTH);
	p = (STRUCT_BUFFER *) malloc (sizeof(STRUCT_BUFFER) * LENGTH);
	// strcpy(p,)
	// q=p;
	for (int i=0; i < LENGTH; i++) {
		q=p+i;
		p[i].buffer_1 = i;
		p[i].buffer_2 = 10000000000.0+i;
		p[i].buffer_3 = i*20;
		p[i].buffer_4 = 42294967296 + i;

		printf("[%d] values:\nbuffer_1: %d\nbuffer_2: %f\nbuffer_3: %d\nbuffer_4 is %lld\n",i, q->buffer_1, q->buffer_2, q->buffer_3, q->buffer_4);
		printf("[%d] address:\nbuffer_1: %p\nbuffer_2: %p\nbuffer_3: %p\nbuffer_4 is %p\n", i,&q->buffer_1, &q->buffer_2, &q->buffer_3, &q->buffer_4);
	}


	//pointer, only needs to clear the allocated p
	free(p);
}