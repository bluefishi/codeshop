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


void itoa(int n, char* s)
{
	char *p = s;
	unsigned int x = n;
	int sig = 0;
	if(n < 0)
	{
		sig = 1;
		x = -n;
	}
	do
	{
		*s++ = x % 10 + '0';
	}while(x /= 10);
	if(sig)
		*s++ = '-';
	*s = 0;
	reverse(p);
}

int main()
{
	int n = -89;
	char s[100];
	itoa(n, s);
	printf("num = %d, string = %s\n", n, s);
	return 0;
}

