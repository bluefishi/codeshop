//http://leetcode.com/onlinejudge#question_47
//通过排序找下一个permutation
class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            sort(num.begin(), num.end());
            res.push_back(num);
            while(true)
            {
                int last = num.size() - 1;
                for(;last >= 1; --last)
                {
                    if(num[last - 1] < num[last])
                      break;
                }
                if(last <= 0)
                  break;
                int swap = num.size() - 1;
                while(swap >= last)
                {
                    if(num[swap] > num[last - 1])
                      break;
                    --swap;
                }
                int tmp = num[last - 1];
                num[last - 1] = num[swap];
                num[swap] = tmp;
                sort(num.begin() + last, num.end());
                res.push_back(num);
            }
            return res;
        }

};

