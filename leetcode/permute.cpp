//http://leetcode.com/onlinejudge#question_46
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        permute(num, 0, res);
        return res;
    }
    
    void permute(vector<int>& num, int i, vector<vector<int> >& res)
    {
        if(i == num.size())
        {
            res.push_back(num);
            return;
        }
        int tmp;
        for(int k = i; k < num.size(); ++k)
        {
            tmp = num[i];
            num[i] = num[k];
            num[k] = tmp;
            permute(num, i + 1, res);
            tmp = num[i];
            num[i] = num[k];
            num[k] =tmp;
        }
    }
};

