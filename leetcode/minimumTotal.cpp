//http://leetcode.com/onlinejudge#question_120
//dynamic programming
//dp[j] = min(dp[j], dp[j-1]) + triangle[i][j-1]
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.size() == 0)
          return 0;
        vector<int> dp(triangle.size() + 1, 0x7fffffff);
        dp[1] = triangle[0][0];
        for(int i = 1; i < triangle.size(); ++i)
        {
            for(int j = triangle[i].size(); j > 0; --j)
            {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j-1];
            }
        }
        int minTotal = dp[1]; 
        for(int i = 1; i <= triangle.size(); ++i)
          if(dp[i] < minTotal)
            minTotal = dp[i];
        return minTotal;
    }
};
