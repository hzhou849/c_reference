#include <stdio.h>

int main ( int argc, char **argv)
{
	char str1[] =  "Hello"; //array
	char *str2 = "Goodbye"; // pointer variable, this will store the address of 'Goodbye' not the value
	str2 = &str1;
	printf("%d %d %s\n", &str1, str1, str1);
	printf("%d %d %s\n", &str2, str2, str2);

	char get_str2;
	get_str2 = *str2;
	printf( "%d %d\n", str2, &str2);


	return 0;
}