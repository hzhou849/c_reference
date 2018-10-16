/* Muti-threaded program 
 * http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html
 * pthread_join() : 
 *  join w/ a terminated thread.
 *  function waits for a thread specified by thread to terminnate
 * 	If thread is already terminated, then function returns immediately.
 * 					
 * pthread_detach() : marks the thread identified by thread as detached.
 * 					When detached thread terminates, its resources are
 * 					automatically released back to the system w/o the
 * 					need for another thread to join w/ the terminated
 * 					thread. 
 * 					* once thread is detached, it cannot be joined with pthread_join()
 * 					  or made joinable again
 * 
 * pthread_self() : return the thread ID use format specifier %u to return value.
 */

#include <stdio.h>		// std io routines
#include <stdlib.h>
#include <pthread.h>	// pthread functions and data structures

/* function to be executed by the new thread */
void *thread_print(void * data) {
	int my_data = (int) data; 	// data recived by thread
	pthread_t tid; 

	tid = pthread_self();
	pthread_detach(pthread_self());		//pthread_self gets pid of thread
	printf("Hello from new thread tid:%u, data passed: %d\n",tid, my_data);
	pthread_exit(NULL);					// Terminate the thread
}

int main(int argc, char *argv[])
{
	int rc;					// return value
	pthread_t thread_id;		// thread's ID (just an int)
	pthread_t tid;				//store the thread ID
	int t = 11;				// data passed to the new thread


	tid = pthread_self();
	int t = (int) tid;
	/*create a new thread that will execute 'thread_print()'*/
	rc = pthread_create(&thread_id, NULL, thread_print, (void *)t); 

	if (rc) {
		printf("\n ERROR: return code from pthread_create is %d \n", rc);
		exit(1);
	}
	printf("\n tid: %u, Created new thread (%u)....\n",tid, thread_id);

	pthread_exit(NULL); 	//terminate the thread


}