//http://leetcode.com/onlinejudge#question_128
//map可解
class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int maxLen = 0;
            map<int, int> countMap;
            for(int i = 0; i < num.size(); ++i)
            {
                countMap[num[i]] = 1;
            }
            for(int i = 0; i < num.size(); ++i)
            {
                int curLen = countMap[num[i]];
                if(curLen != 0)
                {
                    int start = num[i] - 1;
                    while(countMap.find(start) != countMap.end())
                    {
                        curLen += countMap[start];
                        countMap[start] = 0;
                        --start;
                    }
                    if(curLen > maxLen)
                      maxLen = curLen;
                    countMap[num[i]] = start;
                }
            }
            return maxLen;

        }
};
