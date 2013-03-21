#include<stdio.h>
#include<ctype.h>
//strcmp输入两个字符串，如果相等，输出0；如果不等输出第一个不等字符的差值。

int strcmp(char* s, char* t)
{
	while(*s == *t && *s)
	{
		++s;
		++t;
	}
	return *s - *t;
}

int strncmp(char* s, char* t, int n)
{
	if(n <= 0)
	  return 0;
	int i = 1;
	while(*s == *t && *s && i < n)
	{
		++s;
		++t;
		++i;
	}
	return *s - *t;
}

int main()
{
	printf("strcmp(hello, helloworld) = %d\n", strcmp("hello", "helloworld"));
	printf("strcmp(hello, hellu) = %d\n", strcmp("hello", "hellu"));
	printf("strcmp(hellu, hello) = %d\n", strcmp("hellu", "hello"));
	printf("strcmp(hello, hello) = %d\n", strcmp("hello", "hello"));
	printf("strncmp(hello, helloworld, 5) = %d\n", strncmp("hello", "helloworld", 5));
	printf("strncmp(hello, helloworld, 10) = %d\n", strncmp("hello", "helloworld", 10));
	printf("strncmp(hello, hellu, 15) = %d\n", strncmp("hello", "hellu", 15));
	return 0;
}

