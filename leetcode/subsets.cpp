//http://leetcode.com/onlinejudge#question_78
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        int* subset = new int[S.size()]; 
        vector<vector<int> > res;
        subsets_internal(subset, S, res, 0, 0);
        delete[]subset;
        return res;
    }
    void subsets_internal(int subset[], vector<int>& S, vector<vector<int> >& res, int index, int oindex) 
    {
        if(oindex == S.size())
        {
            vector<int> vec(subset, subset + index);
            res.push_back(vec);
            return;
        }
        
        subsets_internal(subset, S, res, index, oindex + 1);
        subset[index] = S[oindex];
        subsets_internal(subset, S, res, index + 1, oindex + 1);
    }
};
