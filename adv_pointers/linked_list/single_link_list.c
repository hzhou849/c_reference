/* 
 * Singly link list
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct d_container {
	struct d_containter *next;
	int  data;
	char arr[10]; 
}D_CONTAINER;

typedef struct listitem {
	struct listitem *next;		// ptr to next item
	int data;					// some data
} LISTITEM;

int main() {
	LISTITEM *listhead, *temp;

	printf("sizeof LISTITEM: %d\n\n", sizeof(LISTITEM));
	//initialize listhead as NULL
	listhead = NULL;

	//now populate the list
	for (int i=0; i < 3; i++) {
		temp = malloc(sizeof(LISTITEM)); // create a new struct
		temp->data=i;
		temp->next = listhead; 
		listhead = temp;
	}

	// output the list
	temp = listhead;
	while (temp != NULL) {
		printf("list item: current is %p; next is %p; data is %d\n", temp, temp->next, temp->data);
		temp = temp->next;
	}
	return 0;
}

