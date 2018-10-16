/* alloc, pointer test
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSTRLEN 100	//100 bytes for allocation

int main(int argc, char **argv) {
	char *s; 
	s =(char*)malloc(MAXSTRLEN);		//allocates 100 sizeof char(1byte) = 100bytes
	s[0] = 0;

	strcpy(s, argv[0]);

	printf("s: %s\n", s);

}
