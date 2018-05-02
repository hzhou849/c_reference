#include <stdio.h>


int main(int argc, char *argv[]) {

	int a =0,b =0, j=0,k=0 ;
	for (int i=0; i <5; i++) {
		
		printf("before 	- i: %d, {a++: %d, ++b: %d}\n", i,a,b);
		a=j++; // print first then increment.
		b=++k; // increment first then print.
		printf("after 	- i: %d, {a++: %d, ++b: %d}\n\n", i,a,b);
		

	}
	
	return 0;
}