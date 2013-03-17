/*count the characters, lines and words of text*/
#include<stdio.h>
#define IN 1
#define OUT 0
void main()
{
	int nc = 0;
	int nl = 0;
	int nw = 0;
	int state = OUT;
	int c;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT)
		{
			++nw;
			state = IN;
		}
	}
	printf("nc = %d, nl = %d, nw = %d\n", nc, nl, nw);
}

