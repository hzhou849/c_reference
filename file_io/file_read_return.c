/* File Write prototype 
 *
 * 


 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 	// Required for 'getcwd'
#include <errno.h>
#include <string.h>


#define FIRM_PATH	"/home/howardz/dev_repositories/development_source/diagnostic_scripts/TPSC/tpsc_script_04-13-18/firmware_version.txt"
#define TEST_PATH	"./test.txt"
// char get_firmware_ver() {
// 	char *firmware_ver;
// 	FILE *fd;
// 	fd = open(TEST_PATH,"r");

// 	if (fd == NULL) {
// 		printf("Error! Could not open file\n");
// 		exit(-1); 
// 	}
	
// 	while(fgets(*firmware_ver, sizeof(firmware_ver),fd)!=NULL)

// 	printf("Data read =%s\n", firmware_ver);
// 	fclose(fd);

// 	return *firmware_ver;
// }

char *get_firmware_ver() {
	char * buffer;
	size_t bufsize = 32;
	
	/* allocate memory for buffer */
	buffer = (char *)malloc(bufsize *sizeof(char));
	
	if(buffer == NULL) {
		perror("unable to allocate buffer");
		exit(1);
	}

	FILE *fd;
	fd = fopen(FIRM_PATH, "r");
	getline(&buffer, &bufsize, fd);
	// printf("%s", buffer);

	// free(buffer);
	fclose(fd);

	return buffer;


}

char *get_firmware_ver2() {
	char *buffer;
	size_t bufsize =32;

	buffer = (char *)malloc(bufsize *sizeof(char));

	if(buffer == NULL) {
		perror("unable to allocate buffer");
		exit(1);
	}

	FILE *fd2;
	fd2 = fopen(FIRM_PATH, "r");
	while(fgets(buffer, bufsize, fd2) != NULL) {
		printf("buffer: %c", buffer);
		fputs(buffer, stdout);
	}
	fclose(fd2);
	free(buffer);
	return buffer;
}

int main() {
	char *firm_ver;
	
	firm_ver = get_firmware_ver();
	printf("version: %s",firm_ver );

	char *buffer;
	size_t bufsize =32;

	buffer = (char *)malloc(bufsize *sizeof(char));

	if(buffer == NULL) {
		perror("unable to allocate buffer");
		exit(1);
	}

	int i=0;
	FILE *fd2;
	fd2 = fopen(FIRM_PATH, "r");
	while(fgets(buffer, bufsize, fd2) != NULL) {


		fputs(buffer, stdout);
		i++;
	}
	for(int i=0; i<bufsize; i++) {
		printf("buffer: %c\n", buffer[i]);
		
		if(buffer[i] == '\n') {
			printf("nl detected");
			buffer[i] = '\0';
		}

	}
	printf("final buffer: %s", buffer );
	fclose(fd2);
	free(buffer);

	free(firm_ver); 
	
}

