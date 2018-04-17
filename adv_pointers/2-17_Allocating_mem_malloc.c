/* 2- 17 Example of using malloc
 *
 * NOTE: Malloc allocates memory on the heap
 *       - but local variables declared inside a function are allocated 
 * 		  memory in the stack which are are cleaned up on close
 * 		 - Heap (global data) will continue to exist even upon exit on 
 */


#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXSTRLEN 100		//100 bytes for allocation

char * string_function(char *astring) 
{
	char* s;
	s = (char*)malloc(MAXSTRLEN); // allocates 100x sizeof char* (1byte) = 100bytes
	s[0] = 0;
	strcat(s, "Hello ");
	strcat(s, astring);
	strcat(s, "\n");
	return s;
}

int main (int argc, char **argv) 
{
	printf(string_function("Fred"));
	printf(string_function("Gussie Fink-Nottle"));
	return 0;
}