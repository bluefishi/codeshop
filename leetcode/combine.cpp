//http://leetcode.com/onlinejudge#question_77
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(n < k || n <= 0 || k <= 0)
          return ret;
        vector<int> com(k); 
        combine(n, k, 0, com, ret);
        return ret;
    }

    void combine(int n, int k, int index, vector<int>& com, vector<vector<int> >& ret)
    {
        if(index == com.size())
        {
            ret.push_back(com);
            return;
        }
        for(int i = n; i >= k; --i)
        {
           com[com.size() - 1 - index] = i; 
           combine(i - 1, k - 1, index + 1, com, ret);
        }
    }
};
