/*
 *atof 输入字符串s，输出对应的浮点值,包含可选的-号
 */
#include<stdio.h>
#include<ctype.h>
float atof(char s[])
{
	int i, sig;
	float value = 0;
	float power = 0.1;
	for(i = 0; s[i] != '\0' && isspace(s[i]); ++i);
	sig = s[i] == '-'? -1 : 1;
	if(s[i] == '-')
		++i;
	for(; isdigit(s[i]); ++i)
		value = value * 10 + s[i] - '0';
	if(s[i] == '.')
		++i;
	for(; isdigit(s[i]); ++i)
	{
		value = value + power * (s[i] - '0');
		power /= 10;
	}
	return value * sig;
}
int main()
{
	char* s1 = "-12";
	char* s2 = "12.0";
	char* s3 = "-.01";
	char* s4 = "12.880";
	printf("%s %f\n", s1, atof(s1));
	printf("%s %f\n", s2, atof(s2));
	printf("%s %f\n", s3, atof(s3));
	printf("%s %f\n", s4, atof(s4));
	return 0;
}

