//count # of 1 of integer x
//参数声明为unsigned int，这样保证右移补0
//x 右移一位是 x >>= 1而不是 x >> 1;
//bitcount2 中 x &= x - 1 可以将x中的最右边的1置为0
#include<stdio.h>
int bitcount(unsigned int x)
{
	int b = 0;
	for(; x != 0; x >>= 1)
	{
		if(x & 1)
			++b;
	}
	return b;
}

int bitcount2(unsigned int x)
{
	int b = 0;
	while(x &= x - 1)
		++b;
	return b;
}
int main()
{
	int x;
	scanf("%d", &x);
	printf("count = %d count1 = %d\n", bitcount(x), bitcount(x));
	return 0;
}

