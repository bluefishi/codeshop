//http://oj.leetcode.com/problems/maximal-rectangle/
//Inspired by [1] http://tech-wonderland.net/blog/leetcode-largest-rectangle-in-histogram.html
//把矩阵的每一层都看做是一个直方图的X轴,以O(m*n)的代价计算出每一层的height数组，调用largestRectangleArea方法计算该层的maximalRectangle,取所有层的最大值即可。
//例如:
//     matrix        height
//    0 0 1 0       0 0 1 0
//    0 0 0 1       0 0 0 1
//    0 1 1 1       0 1 1 2
//    0 0 1 1       0 0 2 3

class Solution {
private:
    int largestRectangleArea(vector<int> &height) {
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
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rows = matrix.size();
        if(rows == 0)
          return 0;
        int cols = matrix[0].size();
        vector<vector<int> > height(rows, vector<int>(cols, 0));
        int maxArea = 0;
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    if(i == 0)
                      height[i][j] = 1;
                    else
                      height[i][j] = height[i - 1][j] + 1;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height[i]));
        }
        return maxArea;
    }
};

