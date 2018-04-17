/* 
 * 2-21  REALLOC
 * 
 * realloc - is used to modify and or extend memory that you have previously 
 * allocated.
 */

 int main() 
 {
	 char* s;
	 int i;

	 i = sizeof("hello");
	 s = (char*)malloc(i);
	 strncpy(s, "helloworld",i);
	 printf("s is %s; %p\n",s, &s);

	realloc(s, 12);		//realloc which frees
	strncpy(s, "hello", i);
	strcat(s, " worldasdfasdf");
	printf("s is now %s; %p\n", s, &s);

	free(s);

	return 0;
 }