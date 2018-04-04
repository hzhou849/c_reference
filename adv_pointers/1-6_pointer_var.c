#include <stdio.h>

/* '&' "address of" operator */
/* *var only store &var2 */
int main(int argc, char **argv)
{
	int num;
	int *numPtr; /* pointer variable points to mem location containing int */
	int num2;

	num = 100;
	numPtr = &num;
	num2 = *numPtr; /* '*' returns the data (dereferencing/indirection) */

	printf("num=%d\n numPtr=%d\n address of num=%d\n num2=%d\n", num, numPtr, &num, num2);
	return 0;
}