/*
 * Note: Unsigned 64-bit with a clock freq. of 100ticks/secs. That corresponds to a clock wraparound of 1.8x10^17 seconds 
 * 		 or 5.8x10^9 yrs
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		//declares sysconf()
#include <stdint.h> 	// used for casting clock_t to uintmax_t for printf
#include <sys/times.h>	//needed for the times() system call

int main (int argc, char **argv) {
	struct tms t;		// parameter to times() - we'll ignore it
	unsigned long freq; 	//clock freq
	uintmax_t start;		//start tick value
	uintmax_t end;			//ending tick value

	printf("sizeof(clock_t) = %lu\n", sizeof(clock_t));
	printf("tick frequency is: %lu\n", freq=sysconf(_SC_CLK_TCK));
	

	if ((start = times(&t)) < 0 ) {		// mark start time
		perror("times");
		exit(1);
	}

	sleep(2);
	if ((end = times(&t)) < 0) { 		// mark end time
		perror("times");
		exit(1);
	}

	printf("elapsed time: %ju - %ju = %ju ticks\n", end, start, end-start);
	printf("elapsed time: %5.2f seconds\n", (double) (end-start)/freq);
	exit(0);
}