#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
	struct listitem *next;	// pointer to next item
	int data;				// data container that holds some data
}LISTITEM;

