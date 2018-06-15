/* 3-37 - Doubly linked list
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct listitem {
	struct listitem *next;		//pointer to next item
	struct listitem *prev; 		// pointer to previous item
	int data;					// some data
} LISTITEM;

int main () {
	LISTITEM *temp, head;

	//initialize the head
	head.next = (LISTITEM*)&head;
	head.prev = (LISTITEM*)&head;
	head.data = -1;

	// populate the list
	for (int i=0; i<3; i++) {
		temp = malloc(sizeof(LISTITEM));
		temp->data = i; //0
		temp->next = head.next; 
		head.next = temp;
		temp->prev = &head;
		temp->next->prev = temp; //think of it as [temp->next]->prev or [head.next(value which is temp)].prev aka temp->prev = temp;
	}

	// output the list iterate forward
	temp = head.next;
	while (temp !=&head) {
		printf("forward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
		temp = temp->next;
	}

	// output the list iterate backwards
	temp = head.prev;			//initialize our temporary variable to the tail of the list
	while (temp != &head) {		// keep going until reached the end
		printf("backwards list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
		temp = temp->prev;
	}
}