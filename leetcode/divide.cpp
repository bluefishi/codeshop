//binary dividing
//http://leetcode.com/onlinejudge#question_29
class Solution {
public:
    int divide(int dividend, int divisor) 
{
    // Start typing your C/C++ solution below
	// DO NOT write int main() function
	int mask = 0x80000000;
	int sigm = dividend & mask;
	int sign = divisor & mask;
	int result = 0;
	int lm = -1;
	int ln = -1;
	unsigned int m = dividend >= 0? dividend: -dividend;
	unsigned int n = divisor >= 0? divisor: -divisor;
	unsigned int curDigit = 1;
	unsigned tmp = m;
	int count = 0;
	while(tmp)
	{
		if(tmp & 0x1)
			lm = count;
		count += 1;
		tmp >>= 1;
	}
	tmp = n;
	count = 0;
	while(tmp)
	{
		if(tmp & 0x1)
			ln = count;
		count += 1;
		tmp >>= 1;
	}
	for(int i = 0; i < lm - ln; ++i)
	{
		n <<= 1;
		curDigit <<= 1;
	}
	while(curDigit)
	{
		if(m >= n)
		{
			result |= curDigit;
			m -= n;
		}
		n >>= 1;
		curDigit >>= 1;
	}
	return (sigm ^ sign)? -result:result;
}
};

