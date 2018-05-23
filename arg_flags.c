/*
 * Argument flags code.
 * from kern pg. 117
 * 
 * This sample code shows how using argument command lines to pass 
 * option '-f' flags.
 */ 

#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int getline2(char *line, int max)
{
	int i, c;
	for (i=0; i<max-1 && (((c=getchar())!=EOF)&&(c!='\n'));i++)
		line[i]=c;
	if (i==(max-1)) {
		while((c=getchar())!='\n') {
			++i;
		}
	}
	if (c=='\n'){
		line[i]=c;
		++i;
	}
	line[i]='\0';
	return i;
}

/* find: print lines that match patter from 1st arg */
int main(int argc, char *argv[]) 
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		printf("condition met\n");
		while (c = *++argv[0]) {
			printf("argv: %c.\n", c);
			switch (c) {
				case 'x':
					printf("x %d\n", argc);
					printf("value: %s\n", argv[0]);
					except = 1;
					break;
				case 'n':
					printf("n\n");
					number = 1;
					break;
				case '\0':
					printf("case 0");
					break;
				default:
					printf("find: illeagal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
			printf("argc: %d\n", argc);
		}
	}
	printf("argc: %d\n", argc);
	// change 'argc != 0' if only passing the flag
	if (argc != 1){
		printf("Usage: find -x -n <pattern>\n");

		for (int i=0; i<argc; i++) {
		printf("%s\n", argv[i]);
	}
	}
	// else if(except == 1) {
	// 	printf("x selected\n");
	// }
	// else if(number == 1) {
	// 	printf("n selected");
	// }

	else{
		// function broken , fix this.
		printf("do something\n"); 
		// while (getline2(line, MAXLINE) > 0) {
		// 	lineno++;
		// 	if ((strstr(line, *argv) !=NULL) != except) {
		// 		if (number)
		// 			printf("%ld:", lineno);
		// 		printf("%s", line);
		// 		found++;
		// 	}
		// }

	}

	for (int i=0; i<argc; i++) {
		printf("argv[%d] - %s\n",i, argv[i]);
	}
	return found;
}