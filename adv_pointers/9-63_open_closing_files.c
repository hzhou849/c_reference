/*
 * 9.63 - Opening Closing files
 * 
 * fopen_s(); - this secure option, check to see if your compiler has this function
 * 
 * Open Options:
 *  'b' is for binary files.
 * 
 * - "r" / "rb"	 - Opens for reading, if the file does not exist or cannot be found, the call 
 *				to topen() fails and 0 ( or the predefined constant NULL) is returned.
 *
 *	"w"  / "wb"		- Opens an empty file for writing. If the given file exists, its contents are
 *			  destroyed.
 *
 *  "a"		- (Append mode) Opens for writing at the end of file. Creates the file
 * 			  if it does not exists.
 * 
 *  "r+"	- Opens for both reading and writing. The file must exist
 * 
 *  "w+"	- Opens an empty file for both reading and writing. If the files exists,
 * 				the contents are destroyed.
 * 
 *  "a+" 	- Opens for reading and appending. Creates the file if it does not exists.

 * 
 */

#include <stdio.h>

#define MAXSTRLEN 200
#define FILENAME "test.txt"

void readlines() {
	FILE *fp = fopen( FILENAME, "r");
	char line[MAXSTRLEN];
	if ( fp !=0 ) {
		while (fgets (line, sizeof(line), fp ) !=0 ) {
			fputs (line, stdout);
		}
		fclose(fp);
	} else {
		printf("File %s cannot be openened!", FILENAME);
	}
}

void writelines() {
	FILE *fp;
	fp = fopen(FILENAME, "w");
	fputs(" output data\n");
	fputs("current, voltage etc...");
	fclose(fp);
}

void clearfile() {
	FILE *fp;
	fp = fopen(FILENAME, "w");
	fclose(fp);
}

void deletefile() {
	if (remove(FILENAME) == 0) {
		printf("%s file deleteded.\n", FILENAME);
	} else {
		printf("Unable to delete the file: %s.\n", FILENAME);
	}
}

int main(int argc, char **argv) 
{
	//deletefile();
	//clearfile();
	writelines();
	readlines();
	return 0;
}


