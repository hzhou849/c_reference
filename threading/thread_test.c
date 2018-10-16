/* Multi threading tester
 * 
 * to compile: gcc -o <fileout> <filename> -lpthread
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Thread executed function */
void *thread_tester(void * vargp) 
{
	sleep(1);
	printf("execution from thread\n");
	return NULL;
}

int main() {
	pthread_t thread_id;
	printf("pre multi-threading\n");
	pthread_create(&thread_id, NULL, thread_tester, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}
