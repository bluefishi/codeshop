//http://leetcode.com/onlinejudge#question_118
class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > ret(numRows);
            if(numRows == 0)
              return ret;
            ret[0].push_back(1);
            for(int i = 1; i < numRows; ++i)
            {
                ret[i].push_back(1);
                for(int j = 0; j < i - 1; ++j)
                  ret[i].push_back(ret[i - 1][j] + ret[i -1][j+1]);
                ret[i].push_back(1);
            }
            return ret;
        }
};

