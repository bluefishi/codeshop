#include<stdio.h>
char* strcat(char* src, char* dest)
{
	char* p = dest;
	while(*dest++);
	dest -= 1;
	while(*dest++ = *src++);
	return p;
}

int main()
{
	char s[100];
	char s1[100];
	while(1)
	{
		gets(s);
		gets(s1);
		printf("%s\n", strcat(s1, s));
	}
}

