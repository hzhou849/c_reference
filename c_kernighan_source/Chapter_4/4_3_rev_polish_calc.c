/* Chapter 4.3 -- REVERSE POLISH Calculator
*
*/

#include <stdio.h>
#include <stdlib.h> // for atof() - in K&R, math.h is reference  - this is anachronism

#define MAXOP 100 	// max size of operand or operator
#define NUMBER '0' 	// signal that a number was found 

int getop (char []);
void push(double);
double pop(void);

/* reverse Polish calculator*/
int main(void) 
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = gettop(s)) !=EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
		}
	}
}