/* Thread variable
 * Show multiple threads share data segment. Global and static variables are
 * stored in data segment. Therefore, they are shared by all threads.
 * As per this example
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Create a global variable to change it in threads */
int g = 0;

/* Function to be executed by all threads */
void *thread_exec(void *vargp) 
{
	/*store the value argument passed to this thread */
	int *myid = (int*)vargp;

	/*create a static variable to observe its changes */
	static int s = 0;

	/* change static and global variables */
	++s; ++g;

	/* Print the argument, static and global variables */
	printf("Thread ID: %d, Static: %d, Global %d\n", *myid, ++s, ++g);

}

int main()
{
	int i;
	pthread_t tid;

	/*Create three threads */
	for(i =0; i < 3; i++){
		pthread_create(&tid, NULL, thread_exec, (void*)&i);
	}
	pthread_exit(NULL);
	return 0;
}

