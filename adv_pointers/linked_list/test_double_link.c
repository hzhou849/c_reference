#include <stdio.h>
#include <stdlib.h>

typedef struct listitem {
	struct listitem *next;
	struct listitem *prev;
	int data;
}LISTITEM;

int main() {
	LISTITEM *temp, head;

	head.next = (LISTITEM*)&head; //cast to LISTITEM pointer type
	head.prev = (LISTITEM*)&head;
	head.data = -1;

	for (int i=0; i<5; i++) {
		temp = malloc(sizeof(LISTITEM));
		temp->data = i;
		temp->next = head.next;
		head.next = temp;
		temp->prev = &head;
		temp->next->prev = temp;
	}


	//forward iteration
	temp = head.next;
	while (temp !=&head) {
		printf ("current: %p; next: %p; prev: %p; data: %d\n", temp, temp->next, temp->prev, temp->data);
		temp = temp->next;
	}
}
