#include <stdio.h>

int main (void)
{
	int number = 100;
	int number2;
	int *numPtr; //address type variable Stores address not value
	int address;

	address = &number;
	// numPtr = &number; //assigns address
	number2 = *numPtr; //stores the actual value NOT address

	printf("number: %d \n numPtr: %d\n number2: %d, &number: %d", number, numPtr, number2, address);
}