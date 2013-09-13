//http://leetcode.com/onlinejudge#question_132
//动态规划，类似于矩阵连乘
//如果用矩阵连乘的话dp[i][j] = 0 if str[i...j] is valid, otherwise
//dp[i][j] = min(dp[i][k]+dp[k+1][j]) + 1 for i<=k<j
//这样的话需要O(n^3)
//考虑可以使用下面的动态规划
//dp[i]代表str[0...i]
//dp[i] = 0 if str[0...i] is valid, otherwise
//dp[i] = min(dp[j] + 1) if str[j+1...i] is valid, for 0<=j<i
//但是判断str[i...j]是否为valid仍然需要O(n)
//可以同样适用动态规划来做
//dp[i][j] == s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])
class Solution {
    public:
        int minCut(string& s)
        {
            if(s.length() == 0)
              return 0;
            vector<vector<bool> > dpValid(s.length(), vector<bool>(s.length(), false));
            for(int i = 0; i < s.length(); ++i)
              dpValid[i][i] = true;
            vector<int> dpMin(s.length(), 0);
            dpMin[0] = 0;
            for(int i = 1; i < s.length(); ++i)
            {
                dpValid[0][i] = s[0] == s[i] && (0 + 1 > i - 1 || dpValid[0 + 1][i - 1]);
                if(!dpValid[0][i])
                {
                    dpMin[i] = 0x7fffffff;
                    for(int j = 0; j < i; ++j)
                    {
                        dpValid[j+1][i] = s[j+1] == s[i] && (j + 2 > i - 1 || dpValid[j+2][i-1]);
                        if(dpValid[j+1][i] && dpMin[j] + 1 < dpMin[i])
                          dpMin[i] = dpMin[j] + 1;
                    }
                }
            }
            return dpMin[s.length()-1];
        }

};

