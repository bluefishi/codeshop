//http://oj.leetcode.com/problems/largest-rectangle-in-histogram/
//Inspired by [1]http://tech-wonderland.net/blog/leetcode-largest-rectangle-in-histogram.html
//&& [2]http://discuss.leetcode.com/questions/259/largest-rectangle-in-histogram?sort=votes
//对于每一根柱子，它都唯一对应了以自己为高度的一个极大矩形区域，其左边界是它左边第一个比它矮的
//其右边界是它右边第一个比它矮的，这样很容易产生O(n^2)的算法。
//[2]中提到increaseing stack 的一个数据结构，其实就是一个stack，不过它中的元素，从栈底到栈顶是
//递增的序列，我们从头扫描高度数组，只要当前位置的高度大于栈顶，就直接push进去，否则，持续pop堆栈，直到
//栈顶的高度小于当前高度。注意从堆栈中pop出来的元素的右边界都是当前位置，左边界都是它的左邻居。因此可以
//在出栈的时候立刻计算出来这些位置的柱子对应的极大矩形的面积。
//下面的代码在一开始往高度数组中push进去了一个高度为0的柱子，这样保证所有的高度都被pop出来。
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<int> pos;
        height.push_back(0);
        int i = 0;
        int maxArea = 0;
        while(i < height.size())
        {
            if(pos.empty() || height[pos.top()] < height[i])
              pos.push(i++);
            else
            {
                int t = pos.top();
                pos.pop();
                int left = pos.empty()?-1:pos.top();
                maxArea = max(maxArea, height[t] * (i - left - 1));
            }
        }
        height.pop_back();
        return maxArea;
    }
};

