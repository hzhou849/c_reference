#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


#define STACKSIZE 5

typedef struct {
	int reg_a;
	int reg_b;
} DATA_STACK;

DATA_STACK *base;
DATA_STACK *end;
DATA_STACK *top;


int push(DATA_STACK* data ) {
	int check_ok;

	if (top == end) {		// if top == end; means stack size limit reached.
		check_ok=0; 				// return a '0' to throw not proceed
	} else {
		memcpy (top, data, sizeof(DATA_STACK));  // transfer the contents from temp holder to stack 
		top = top +1;						// increase the stack count to new top position
		check_ok = 1;
	}
	return check_ok;
}

DATA_STACK* pop() {
	DATA_STACK* data;

	if (top == base) {		//empty stack
		data = NULL;
	} 
	else {
		top = top -1;		// set top to top-1 and get the top itm and return it
		data = top;
	}
	return data;
}

int main() {
	DATA_STACK data, *pdata;

	base = (DATA_STACK*)malloc(STACKSIZE * sizeof(DATA_STACK));
	end = base + STACKSIZE;
	top = base;

	// add data items to the stack 
	for (int i = 0; ;i++) {
		data.reg_a = i;
		data.reg_b = i*2;

		if (!push(&data)) {
			printf("***\n");
			break;
		}
	}

	printf("first item = %d : %d\n", base->reg_a, base->reg_b);
	pdata = base + 4; 		// assign 4th item up from base
	printf("last item = %d : %d\n\n", pdata->reg_a, pdata->reg_b );

	do {
		pdata = pop();
		if (pdata !=NULL) {	// sleep (1);
			printf("data popped: %d : %d\n", pdata->reg_a, pdata->reg_b);
		}

	} while (pdata != NULL);


	free(base);
	return 0;
}


