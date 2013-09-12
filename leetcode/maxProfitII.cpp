//http://leetcode.com/onlinejudge#question_122
//数据一定是折线形状的，所以只要在低点买入，高点卖出即可。
//前面的特殊情况判断是必要的，否则prices.size() - 1溢出会提升到unsigned int的最大值
class Solution {
    public:

        int maxProfit(vector<int>& prices)
        {
            if(prices.size() < 2)
              return 0;
            int i = 0;
            int profit = 0;
            int start = 0;
            while(i < prices.size() - 1)  
            {
                start = i;
                while(i < prices.size() - 1 && prices[i] < prices[i+1])
                  ++i;
                if(start != i)
                  profit += prices[i] - prices[start];
                while(i < prices.size() - 1 && prices[i] >= prices[i+1])
                  ++i;
                start = i;
            }
            return profit;
        }

};

