#include<stdio.h>
void reverse(char* s)
{
	char* e = s;
	while(*e++);
		e -= 2;
	char c;
	while(s < e)
	{
		c = *s;
		*s = *e;
		*e = c;
		++s;
		--e;
	}
}

int main()
{
	char s[100];
	gets(s);
	reverse(s);
	printf("%s\n", s);
}

