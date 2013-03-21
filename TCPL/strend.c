#include<stdio.h>
#include<ctype.h>
#include<string.h>
//strend 输入两个字符串s，t，如果t出现在s的尾部返回1，否则返回0
int strend(char* s, char* t)
{
	char* s1 = s;
	char* t1 = t;
	while(*s1++);
	while(*t1++);
	while(s1 >= s && t1 >= t && *s1-- == *t1--);
	if(t1 < t)
		return 1;
	return 0;
}

int main()
{
	printf("%d\n", strncmp("h", "h", 0));
	printf("strend(hellworld, world) = %d\n", strend("helloworld", "world"));
	printf("strend(helloworld, worle) = %d\n", strend("helloworld", "worle"));
	printf("strend(hello, hellworld) = %d\n", strend("hello", "helloworld"));
	return 0;
}

