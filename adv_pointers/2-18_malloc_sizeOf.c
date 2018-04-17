/*
 *
 * NOTE: if strncpy is giving you compile error, 
 * add "#define _CRT_SECURE_NO_WARNINGS" on top of file (line 1 literally)
 * 2- 18 Malloc and SizeOf
 * 
 * A very simple allocation of memory and changing something in the newly
 * allocated memory
 * 
 * when using malloc "(char*)" cast is used because malloc always returns a 
 * generic pointer type of 'void*'
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() 
{
	char* s;
	int stringSize;

	stringSize = sizeof("hello"); //get the size of "hello"
	printf("size of 'hello' is %d\n", stringSize);	//NOTE: this is 6bytes long  (5 +null terminator)


	// allocate size 'char*' for stringSize (6bytes)
	s = (char*)malloc(stringSize);

	// Malloc will return 0 (NULL) if failed
	if (s == NULL) {
		printf("malloc failed!\n");
		exit(0);
	}

	// Now copy the string into the newly allocated memory
	strncpy(s, "hello", stringSize);

	// and change the first character (just to show we can)
	printf("s is %s\n", s);
	s[0] = 'c';
	printf("s is now %s\n", s);
	return 0;

}