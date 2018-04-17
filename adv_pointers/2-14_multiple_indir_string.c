/* 2-14 Multiple Indirection with Strigns 
* '**pptr' pointer to pointers are used bc string is an array of chars think of
* it as **ptr == *array[]
* Another example is how main **argv is equivalent to *argv[] 
*/

#include <stdio.h>


#define LENGTH 3

char* words[LENGTH];		// strings array container

int main (int argc, char **argv) {
	char *pc;				// a pointer to a character
	char **ppc;				// a pointer to a pointer to a character

	printf ("multiple indirection example\n");

	//initialize our string array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	for (int i=0; i<LENGTH; i++) {
		printf("%s\n", words[i]);
	}

	/*B: a pointer to an array of strings
		- the same pointer as a pointer to a pointer to a char*/

	printf("\nNow print the chars in each string...\n");
	ppc = words;			//initialize pointer to a pointer to a char
	for (int i=0; i<LENGTH; i++) {
		ppc = words + i;
		pc = *ppc;			// dereferenceing *ppc

		while (*pc !=0) { 
			printf("%c ", *pc);
			pc += 1;
		}
		printf("\n");
	}

	return 0;

}


