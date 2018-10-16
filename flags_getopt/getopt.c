/* Getopt command line flag handler
 *
 * An example of how to implement the Getopt flag function
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void show_usage(char  **argv) {
	fprintf(stderr, "usage: %s [-ilw] [file...]\n", argv[0]);
}

int main(int argc, char **argv)
{
	int opt;
	bool isCaseSensitive = false;
	
	/* if no arguments are passed */
	if (argc <1) {
		show_usage(argv);
	}


	enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode = CHARACTER_MODE; 
	while((opt = getopt(argc, argv, "ilw")) != -1) {
		switch(opt) {
			case 'i': 
				printf("i condition\n");
				isCaseSensitive = true; 
				break;
			case 'l':
				printf("l condition\n");
				mode = LINE_MODE;
				break;
			case 'w':
				printf("w condition\n");
				mode = WORD_MODE;
				break;
			default:
				show_usage(argv);
				exit(EXIT_FAILURE);
		}
	}
	printf("running\n");



}