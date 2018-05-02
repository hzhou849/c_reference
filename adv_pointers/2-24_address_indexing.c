/*
 * 2-24 Address Indexing 
 * This sample code shows the size types of memory allocations
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int a[COUNT];
float b[COUNT];
double c[COUNT];
long long int d[COUNT];
short int e[COUNT];
long int f[COUNT];


//illustrate the different amounts that are added to an address by C's address arithmetic
int main()
{
	int*	pa;
	float	*pb;
	double*	pc;
	long long int* pd;
	short int* pe; //we could just use 'short' here
	long int* pf;

	// display the sizes of our arrays
	printf("sizes are: int %d; float %d; double %d; long long int %d; short int %d; long int %d\n", sizeof(int), sizeof(float),
		 sizeof(double), sizeof(long long int), sizeof(short int), sizeof(long int));
	//NOTE: because of historical reasons a plain 'int' can vary in size btwn machine architectures. On some 
	// microprocessors it is 2 bytes long while on Intel processors it is 4 bytes.
	// If we want to be explicit (and more portable), then use 'long int' for a 32bit integer instead of just 'int'

	// Inititalize our array and pointers
	pa =a;
	pb = b;
	pc = c;
	pd = d;
	pe = e;
	pf = f;
	for (int i=0; i<COUNT; i++) {
		a[i]=i;
		b[i]=(float)i; // cast required
		c[i]=(double)i; //cast
		d[i] = i;
		e[i] = i;
		f[i] = i;
	}

	// Pointer arithmetic
	pa += 1;
	pb += 1;
	pc += 1;
	pd +=1;
	pe +=1;
	pf +=1;

	// pritn the results
	printf("address of a is %p [%d]; value of pa is %p [%d]; value pointer to by pa is %d\n", a, a, pa, pa, *pa);
	printf("address of b is %p [%d]; value of pb is %p [%d]; value pointed to by pb is %f\n", b,b, pb, pb, *pb);
	  printf("address of c is %p [%d]; value of pc is %p [%d]; value pointed to by pc is %f\n", c, c, pc, pc, *pc);
    printf("address of d is %p [%d]; value of pd is %p [%d]; value pointed to by pd is %lld\n", d, d, pd, pd, *pd);
    printf("address of e is %p [%d]; value of pe is %p [%d]; value pointed to by pe is %hd\n", e, e, pe, pe, *pe);
    printf("address of f is %p [%d]; value of pf is %p [%d]; value pointed to by pf is %ld\n", f, f, pf, pf, *pf);

	// int *ptest;
	// int var = 8;
	// printf("init ptest address: %p", ptest);
	// &var=(int*)0x60110;
	// ptest=&var;
	// printf("address of ptest: %p value: %d", ptest, *ptest);

	return 0;
}