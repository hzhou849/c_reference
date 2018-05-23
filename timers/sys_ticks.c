/*
 * Ticks counter.
 *  Reports times used by the  current process times.
 * 
 * Times system call gets the user time and system time used by the current process and its children.
 * 
 * User Time - is the time that the processor spent executing instructions in the process.
 * System time - is the time that the processor spent in the OS executing instructions
 *               on behalf of the process.
 * 
 * Times System call has the following usage:
 *  #include <sys/times.h>
 * 
 * clock_t times(struct tms *buf);
 *  
 *
 * https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/times.html
 */

#include <stdio.h> 	// defines printf()
#include <stdlib.h> 	// to define exit()
#include <unistd.h> 	// sysconf()
#include <stdint.h> 	// used for casting clock_t to uintmax_t for printf
#include <sys/times.h> 	// needed for the times() system call
#include <sys/types.h> 
#include <sys/stat.h>	// used for open()
#include <fcntl.h>		//used for open()




void kill_time (void) {
	long long i, j; 	// use these in a loop to kill time
	int fd;
	char buf[2048];

	printf("consuming cpu cycles...\n");
	for (i=0; i<100000000; i++){
		j +=i;
	}

	printf("wasting kernel resources...\n");
	//do stuff to waste system time

	//thius statement will attempt to open FD and error if something goes wrong.
	if ((fd=open("/dev/urandom", O_RDONLY)) < 0) {
		perror("open");
		exit(1);
	}

	for (i=0; i<1000; i++) {
		read(fd,buf, 2048);
	}
	close(fd);

}

int main (int argc, char **argv) {
	// clock_t times(struct tms * buf);
	struct tms t;		// the time values will be placed into this struct
	// clock_t start = clock();

	printf("tick frequency is : %lu\n", sysconf(_SC_CLK_TCK));

	kill_time();		// Do something with some time.
	if (times(&t) < 0) {
		perror("times");
		exit(1);
	}

	//Print the results
	printf("user time: %ju ticks\n", (uintmax_t) t.tms_utime);
	printf("system time: %ju ticks\n", (uintmax_t) t.tms_stime);
	printf("children - user time: %ju ticks\n", (uintmax_t) t.tms_cutime);
	printf("children - system time: %ju ticks\n", (uintmax_t) t.tms_cstime);

	exit(0);
}