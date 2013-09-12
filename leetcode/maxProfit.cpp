//http://leetcode.com/onlinejudge#question_121
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() < 2)
          return 0;
        int curMin = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < curMin)
              curMin = prices[i];
            if(prices[i] - curMin > maxProfit)
              maxProfit = prices[i] - curMin;
        }
        return maxProfit;
    }
};
