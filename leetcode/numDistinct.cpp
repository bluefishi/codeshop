//sigh，又是动态规划，跟editdistance很像
//dp[i][j] = dp[i-1][j]
//           dp[i-1][j] + dp[i-1][j-1] if S[i-1]==T[j-1]
//http://leetcode.com/onlinejudge#question_115
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(T.length() + 1);
        dp[0] = 1;
        for(int i = 1; i <= S.length(); ++i)
        {
            for(int j = min((int)T.length(), i); j >= 1; --j)
              dp[j] = dp[j] + (S[i-1]==T[j-1])*dp[j - 1];
        }
        return dp[T.length()]; 
    }
};

