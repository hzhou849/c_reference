/* 
 *he clock library function (not system call) provides an analogous approach to the return 
 value of times to mark start and end times. Clock takes no parameter and returns an estimate
  of the processor time used by the running process. The starting time value is undefined 
  so you need to resort to reading the start and end times and then computing the difference, 
  just as we did with times.


 *
 * The big difference between measuring with clock and times is that clock measures approximate 
 * process time used while times returns overall elapsed time. If you try the above program 
 * that sleeps for two seconds with clock, you will get a value of 0 elapsed seconds. 
 * Basically, the call to sleep put the process to sleep and there was no CPU time used on
 *  behalf of the process during that time.
 */

#include <stdio.h>		/* declares printf() */
#include <stdlib.h>		/* declares exit() */
#include <stdint.h>		/* used for casting clock_t to uintmax_t for printf */
#include <time.h>		/* needed for the clock() library function */

int
main(int argc, char **argv) {
	unsigned long freq;	/* clock frequency */
	uintmax_t start;	/* starting tick value */
	uintmax_t end;		/* ending tick value */

	start = clock(); 	/* mark the start time */
	sleep(2);	/* sleep for two seconds */
	end = clock(); 		/* mark the end time */

	printf("elapsed time: %ju - %ju = %ju ticks\n", end, start, end-start);
	printf("elapsed time: %8.6f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
	exit(0);
}