//http://leetcode.com/oldoj#question_87
//三维的动态规划
//没啥意思
//找出来递归方程即可
//dp[i][j][k]表示从i开始的和从j开始的长度为k的字串是否为scramble
//dp[i][j][k] = (d[i][j][l] && dp[i+l][j+l][k-l]) || (dp[i][j+k-l][l] && dp[i+l][k-l]) for 1<=l<k
//class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s1.length();
        if(len == 0)
          return true;
        vector<vector<vector<bool> > > dp(len, vector<vector<bool> >(len, vector<bool>(len + 1, false)));
        for(int i = 0; i < len; ++i)
          for(int j = 0; j < len; ++j)
            if(s1[i] == s2[j])
              dp[i][j][1] = true;
        for(int k = 2; k <= len; ++k)
        {
            for(int i = 0; i <= len - k; ++i)
            {
                for(int j = 0; j <= len - k; ++j)
                {
                    for(int l = 1; l < k; ++l)
                    {
                        if((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k -l][l] && dp[i + l][j][k - l]))
                        {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][len]; 
    }
};
