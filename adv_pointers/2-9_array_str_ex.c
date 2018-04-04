#include <stdio.h>

// note: that the address of the array is the same address of the first character
// bc it is the address of where the array begins with sequential numbers

int main (int argc, char **argv) 
{
	char str1[] = "Hello World";
	int num = 100;

	/* note: in ubuntu memory ptr in 2's compliments. %d vs %p hex first 4 nibbles are padded '1's for sign 
	printf ("str1: %s\n str1[0]: %c\n address of array &str1: %p\n address of first char &str1[0]: %d\n str1: %d\n", str1, str1[0], &str1, &str1[0],str1);
	return 0;
}