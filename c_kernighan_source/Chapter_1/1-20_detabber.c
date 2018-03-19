/*
* Detabber program. 1-20 pg 34
* This application will replace '\t' tab spaces with appropriate spaces
* Fixed from the website to work
* 
* Write a program detab that replaces tabs in the input with the proper number 
* of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
* say every n columns. Should n be a variable or a symbolic parameter? 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER		1024
#define SPACE			(char) ' '
#define TAB				(char) '\t'
#define SPACE_CHAR		(char) 's'

int CalculateNumberOfSpaces(int Offset, int TabSize)
{
	//for the original question to apply spaces til next tabstop
	// return TabSize - (Offset % TabSize); // 
	return TabSize; // This return is used to apply proper spaces
}

/* K&R's getlie() function from p29 */
int getline1(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

int main(void)
{
	
	char Buffer[MAX_BUFFER];
	int TabSize = 4; //test value


	int i, j, k;
	i = j = k =0;
	while(getline1(Buffer, MAX_BUFFER) > 0) {
		for (i = 0; Buffer[i] != '\0'; i++) {
				j = CalculateNumberOfSpaces(i, TabSize);
			// printiiffeiiputchar(Buffer[i]);
		}
	}
	return 0;
}
