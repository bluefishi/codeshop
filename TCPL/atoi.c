#include<stdio.h>
int atoi(const char* s)
{
	int n = 0;
	while(*s && *s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s += 1;
	}
	return n;
}

int main()
{
	char s[100];
	gets(s);
	printf("%d\n", atoi(s));
}

