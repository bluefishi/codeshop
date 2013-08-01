//http://leetcode.com/onlinejudge#question_67
//还是要注意边界条件啊
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        short addition = 0;
    short x, y;
	int i = 0;
	int j = 0;
	for(i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; --i, --j)
	{
		x = a[i] - '0';
		y = b[j] - '0';
		a[i] = (x + y + addition) % 2 + '0';
		addition = (x + y + addition) / 2;
	}
	if(j >= 0)
	{
		a = string(j + 1, '0') + a;
		for(; j >= 0 ; --j)
		{
			y = b[j] - '0';
			a[j] = ((y + addition) % 2 + '0');
			addition = (y + addition) / 2;
		}
		i = -1;
	}
	
	if(addition)
	{
		for(; i >= 0; --i)
		{
			x = a[i] - '0';
			a[i] = (x + addition) % 2 + '0';
			addition = (x + addition) / 2;
		}
		if(addition)
			a = "1" + a;
	}	
	return a;
    }
};

