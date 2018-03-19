/* 2.3 Hex to Int coverter pg 46
* 
* Converts Hexidecimal 0x to decimal base 10 numbmers
* http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx203.html
*
* Simplified version using everything up to chapter 2
* acceptable 
*/

#include <stdio.h>
#include <stdlib.h>

/* Helper function to get around not having strchr */
int hexalpha_to_int(int c)
{
	char hexalpha[] = "aAbBcCdDeEfF";
	int i;
	int answer = 0;

	for (i = 0; answer == 0 && hexalpha[i] != '\0'; i++)
	{
		if(hexalpha[i] == c)
		{
			// if 
			answer = 10 + (i/2);
		}
	}

	return answer;
}

unsigned int htoi(const char s[])
{
	unsigned int answer = 0;
	int i = 0;
	int valid = 1;
	int hexit;

	if(s[i] == '0') {
		++i;

		if ( s[i] == 'x' || s[i] == 'X') {
			++i;
		}
	}

	while(valid && s[i] != '\0') {
		answer = answer * 16;
		if (s[i] >= '0' && s[i] <= '9'){
			answer = answer + (s[i] -'0');
		}
		else {
			hexit = hexalpha_to_int(s[i]);
			if (hexit == 0) {
				valid = 0;
			}
			else {
				answer = answer + hexit;
			}
		}
		++i;
	}


	if (!valid) {
		answer = 0;

	}
	return answer;

}

int main(void)
{
	char random[] = "char";
	char *endp = NULL;k
	char *test[] = {
		"F00"
		"bar"
		"hjk"
	};

	unsigned int result;
	unsigned check;

	size_t numtests = sizeof test /sizeof test[0];
	size_t thistest;

	for ( thistest = 0; thistest < numtests; thistest ++ ) {
		result = htoi(test[thistest]);
		check = (unsigned int) strtoul(test[thistest], &endp, 16);

		if ( (*endp != '\0' && result == 0) || result == check ) {
			printf("Testing %s. Correct. %u\n", test[thistest], result);
		} else {
			printf("Testing %s. Incorrect. %u\n", test[thistest], result);
		}
	}

	return 0;

	
}

