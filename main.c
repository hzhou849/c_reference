
#include <stdio.h>

void pointerTest() {
    int number = 10;
    int *numPtr;

    printf( "number=%d, numPtr=%d\n", number, numPtr);
   // return 0;
}

void pointerHexFunction() {
    int intAddress=11;
    int hexAddress = 255;
    int *addressPtr;

 // %x - returns hex values
    printf ("address=%d, hexAddress=%x", intAddress, hexAddress);
   //return 0;

}


int main (int argc, char **argv) {
    int num;
    int *numPtr; //pointer variable - stores a pointer address not the value
    int num2;
    num = 100;
    numPtr = &num; //&grabs the address of a variable 
    num2 = *numPtr; //assigning a normal variable a pointer value will return actual value not address
    printf ("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr,&num, num2);
   
    return 0;

    
}



