#include <stdlib.h>
#include <string.h>

typedef struct {
	int a;				// 4 bytes
	int c; 				// 4 bytes
	double b;			// 8 bytes
	long long int d;	// 8 bytes
} MYSTRUCT;

#define COUNT 4

int main()
{
	MYSTRUCT *p, *q;
	void* v;

	// Always use 'sizeof() for allocation!
	printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));
	p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));

	for(int i=0; i<COUNT; i++) {
		p[i].a = i;
		p[i].b = 100000000000.0 +i;
		p[i].c = i * 20;
		p[i].d = 4294967296 + i;
	}

	q = p;
	printf("[0] values: \na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
	printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n", &q->a, &q->b, &q->c, &q->d);

	q = p + 3;
	printf("\n[3] values: \na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
	printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n\n", &q->a, &q->b, &q->c, &q->d);

	// a more advanced way of looking at what is inside the structure (32bytes)
	// NOTE: address arithmetic will not work with generic pointers unless you cast it.
	// 'v = v + 3' (or v[3]) bc the compiler doesn't know what the thing that 'v' (a generic
	// pointer) is pointing to.


	v = p+3; // Look at the third element of the array of MYSTRUCT.
	// Print out the values as integers - the zeros show you hwere the padding has been inserted by the compiler
	// NOTE: Using address arithmetic to move along MYSTRUCT as a set of 8'int' values of 4 bytes each (32 bytes total).	
	printf("Struct at index 3\n");
	for (int i=0; i<sizeof(MYSTRUCT) / sizeof(int); i++) {
		// printf("v[%d]=%d\n", i, (int*)v[i] ); // this will not work
		printf("v[%d]=%d\n", i, ((int*)v)[i] ); // brackets matter and must be placed in this order to work with array pointers

	}
	 free(p);
	return 0;
}

//Because struct data type declaration matters, look at the extra padded bytes in the second output 32bytes.
// 24 bytes int, int, double, longlongint
// Struct at index 3
// v[0]=3
// v[1]=60
// v[2]=-402456576
// v[3]=1110919286
// v[4]=3
// v[5]=1


//Notice the  the extra (4bytes each) padded 0s in v[1], v[5]

//32 bytes declares int, double int, longlongint

// Struct at index 3
// v[0]=3
// v[1]=0
// v[2]=-402456576
// v[3]=1110919286
// v[4]=60
// v[5]=0
// v[6]=3
// v[7]=1
