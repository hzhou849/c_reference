/* Test linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
	struct listitem  *next;
	int data;
}LISTITEM;


int main () {
	LISTITEM *listhead, *temp;
	
	printf("sizeof LISTITEM: %d\n\n", sizeof(LISTITEM));

	/* initialize listhead */
	listhead = NULL;

	/* Populate the list */
	for (int i=0; i<3; i++) {
		temp = malloc(sizeof(LISTITEM)); // create a new struct
		temp->data = i;
		temp->next = listhead;
		listhead = temp; //held in temp for the next iteration
	}

	/*retrieve data records */
	temp = listhead;
	while(temp !=NULL) {
		printf("list item: current:%p, next: %p, data: %d\n", temp, temp->next, temp->data);
		temp = temp->next;
	}
	
	return 0;
}