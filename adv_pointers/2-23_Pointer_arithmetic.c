/*
 * 2-23 Pointer Arithmetic
 * 
 * address of a is 0x7ffec6409f10; value of p is 0x7ffec6409f10 [-968843504]; value pointed by p is 0
 * address of a is 0x7ffec6409f10; value of p is 0x7ffec6409f14 [-968843500]; value pointed by p is 1
 * address of a is 0x7ffec6409f10; value of p is 0x7ffec6409f1c [-968843492]; value pointed to by p is 3
 * 
 * Ubuntu uses two's comp. for memory addressing.
 * 0x77fe <c6409f10> = [-968843504]
 * to get the positive number, take c6409f10 = [-968843504]
 *   i) convert to binary 	1100 0110 0100 0000 1001 1111 0001 0000 
 *  ii) convert to inverse: 0011 1001 1011 1111 0110 0000 1110 1111
 * iii) +1: 				0011 1001 1011 1111 0110 0000 1111 0000
 * iv) convert back to hex: =0x39BF60F0 == 968843504
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define COUNT 4

 int main ()
 {
	int *p;
	int a[COUNT];
	printf("size of an 'int' is %d\n", sizeof(int));

	//iniitialize our array
	for (int i=0; i<COUNT; i++) {
		a[i] =i;
	}

	//Pointer arithmetic
	p=a; 		//sets the pointer to the start of the the array

	printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	p = p+1;
	printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	p = p+2;
	printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a,p,p,*p);

	/* What happens if we go beyond the array end?, theres nothing to stop/warn you*/
	// p= p+1;
	// printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p,p, *p);

	return 0; 			
 }