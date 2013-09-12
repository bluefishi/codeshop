//http://leetcode.com/onlinejudge#question_123
//两次的话，实际上就是从0到n-1选出一个切割点j，算出[0,j],[j,n-1]各自一次的maxProfit，计算出一个最大值
//[0,j]可以O(1)的推算出[0,j+1]
//[j, n-1]无法O(1)的推算出[j+1, n-1]
//但是可以通过提前一次计算出结果保存起来
//不过此时需要从数组后面计算，以当前的index为买入点，并且记录index-->n-1之间的最大price，也就是最好的卖出点
class Solution {
    public:
        int maxProfit(vector<int>& prices)
        {
            if(prices.size() < 2)
              return 0;
            vector<int> rightProfit(prices.size() + 1, 0);
            int rightMaxProfit = 0;
            int rightMaxPrice = prices.back();
            for(int i = prices.size() - 1; i >= 0; --i)
            {
                if(prices[i] >=    rightMaxPrice)
                  rightMaxPrice = prices[i];
                if(rightMaxPrice - prices[i] > rightMaxProfit)
                  rightMaxProfit = rightMaxPrice - prices[i];
                rightProfit[i] = rightMaxProfit;
            }
            int profit = 0;
            int leftMaxProfit = 0;
            int leftMinPrice = prices.front();
            for(int mid = 0; mid < prices.size(); ++mid)
            {
                if(prices[mid] <= leftMinPrice)
                  leftMinPrice = prices[mid];
                if(prices[mid] - leftMinPrice > leftMaxProfit)
                  leftMaxProfit = prices[mid] - leftMinPrice;
                if(leftMaxProfit + rightProfit[mid + 1] > profit)
                  profit = leftMaxProfit + rightProfit[mid+1];
            }
            return profit;
        }

};

