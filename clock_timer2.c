#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define MAX_ITER 1000000000

int main() {
	int i = 0;
	clock_t start, current;
	double difference, seconds;   
	start = clock(); 
	while (i <= MAX_ITER) {
		current = clock();  
		difference = current - start;
		seconds = difference/CLOCKS_PER_SEC;
		int usec = seconds*1000000;   
		if (usec % 10000 == 0) { 
			printf("usec: %d, secs: %.2f\n", usec, seconds); 
		} 
		i++; 
	} 
	return 0; 
} 
