/* Pointer with struct tutorial */

#include <stdio.h>



// Struct declaration
struct object{
	int x;
	float y;
};

void pointerTest() 
{
	int number = 10;
	int number2;
	int *numPtr; // Stores address not value
	numPtr = &number; // assigns address
	number2 = *numPtr; // assigns a normal variable to a pointer value return actual value not address

	printf("num = %d, num");

}

// Instantiate the struct

int main()
{
	struct object object_name;

	// int num;
    // int *numPtr; //pointer variable - stores a pointer address not the value
    // int num2;
    // num = 100;
    // numPtr = &num; //&grabs the address of a variable 
    // num2 = *numPtr; //assigning a normal variable a pointer value will return actual value not address
    // printf("num: %d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr,&num, num2);
   
    // return 0;

	int number;
	int *numberPointer; //Pointer variable - stores address not value.
	int num2;
	
	number = 100;
	numberPointer = &number; // & - grabs the address of variable not value
	num2 = * numberPointer; // assigning a variable with a pointer value will return value not address

	printf("number: %d, numberPointer: %d, address of number: %d, num2_value: %d", number, numberPointer, &number, num2);

	int value;
	int *addressValue; // stores &address not value

	int value2;

	value = 0xFFF;
	addressValue = &value;
	value2 = *addressValue;

	printf("value: %x, *addressValue: %d, &value:%d, value2: %x", value, addressValue, &value, value2);
}