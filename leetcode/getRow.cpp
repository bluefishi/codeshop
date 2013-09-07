//http://leetcode.com/onlinejudge#question_119
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        for(int i = 1; i <= rowIndex; ++i)
        {
            ret[i] = (int)(((long long)ret[i-1]) * (rowIndex - i + 1) / i);
        }
        return ret;
    }
};

