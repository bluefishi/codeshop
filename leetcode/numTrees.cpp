//http://oj.leetcode.com/problems/unique-binary-search-trees-ii/
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
          return 1;
        vector<int> value(n + 1, 0);
        value[0] = 1;
        value[1] = 1;
        for(int k = 2; k <= n; ++k)
        {
            for(int i = 0; i <= k - 1; ++i)
            {
                value[k] += value[i]*value[k-1-i];
            }
        }
        return value[n];
    }
};
