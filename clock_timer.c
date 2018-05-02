#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	int msec =0,  trigger=50000
	; /*10ms*/
	clock_t before = clock();
	int iterations;
	long long int num1=999999999;
	long long int num2 =9999999;
	int value;


	printf("CLOCKS/SEC: %d", CLOCKS_PER_SEC);
do {
	value += num1 +num2 - num1 ^2 /88^num2^num1;

	clock_t difference = clock() - before;
	msec = difference * 1000 / CLOCKS_PER_SEC;
	iterations++;
	if (msec == 2000) {
		printf("Time taken %d seconds %d milliseconds (%d iterations)\n", msec/1000, msec%1000, iterations);
	}

}while (msec < trigger);
}
