/* File write 
 *
 * w+

Opens a text file for both reading and writing. 
It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist.
gets current working directory and assigns it to cwd variable to put outputed
 */

// #include <unistd.h>
// #include <stdio.h>
// #include <errno.h>

// int main() {
//    char cwd[1024];
//    if (getcwd(cwd, sizeof(cwd)) != NULL)
//        fprintf(stdout, "Current working dir: %s\n", cwd);
//    else
//        perror("getcwd() error");
//    return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>			// Required for 'getcwd'
#include <errno.h>			// error handling

int main() {
	char cwd[1024];
	// allocate memory to store the size of the characters for current working directory
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
		perror("getcwd() error");
	
	
	FILE *fp;

	fp = fopen("./test.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs ("This is testing for fputs...\n", fp);
	fclose(fp);
}



// main() {
//    FILE *fp;
//    fp = fopen("/tmp/test.txt", "w+");
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);
//    fclose(fp);
// }