//http://leetcode.com/onlinejudge#question_3
//解题思路http://discuss.leetcode.com/questions/154/longest-substring-without-repeating-characters
//使用一个lookup table来做exist查询
//解题的关键在于从头开始搜索直到第j个位置出现重复，假设和第j个重复的字符排在第i位，那么下次搜索
//只需要从第i+1开始
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		bool lookup[256] = {false};
		int i = 0; 
		int j = 0;
		int maxl = 0;
		int n = s.length();
		while(j < n)
		{
			if(lookup[s[j]])
			{
				maxl = max(maxl, j - i);
				while(s[i] != s[j])
				{
					lookup[s[i]] = false;
					i += 1;
				}
				i += 1;
				j += 1;
			}
			else
			{
				lookup[s[j]] = true;
				j += 1;
			}
		}
		maxl = max(maxl, j - i);
       return maxl; 
    }
};

