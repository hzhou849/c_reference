/* 
 * Memory Buffer malloc
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#define BUF_LENGTH 10			//100 bytes for allocation

void copy_buffer() {
	char src[40];
	char dest[100];

	memset(dest, '\0', sizeof(dest));
	strcpy(src, "This is the src_string\n\n");
	strcpy(dest, src);

	printf("result: %s", dest);

	
}

void dump_buffer(char * buffer) {
	char *tmp_p;
	char **tmp_ppi; // second '*' is required for multiple indirection.

	tmp_p = buffer;
	tmp_ppi = &tmp_p;

	for (int i=0; i< BUF_LENGTH; i++) {
		printf("i: %d; address: %p\n", i, *tmp_ppi);
		tmp_p++;
	}
}


int main () {
	char* mem_buffer;

	// int i;
	char *p;
	// char  temp_def_buf;
	char **ppi;
	// use malloc first to allocate some memory 
	mem_buffer = (char*)malloc(BUF_LENGTH * sizeof(char)); //allocates 100 * char size

	for (int i=0; i<BUF_LENGTH; i++) {
		mem_buffer[i] = i;
		printf("mem_buff[%d]: %d; address: %p\n",i, mem_buffer[i],&mem_buffer[i]);
	}

	p=mem_buffer;
	ppi=&p;
	// temp_def_buf = *p+i;
	for (int i=0; i< BUF_LENGTH; i++) {
		// ppi = &temp_def_buf;
		printf("p_mbuff[%d]: %d; %p\n", i, *p, *ppi);
		p++;
		// ppi+=1;
		// ppi+=1;
	}

	copy_buffer();
	
	dump_buffer(mem_buffer);
}