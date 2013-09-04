//http://leetcode.com/onlinejudge#question_31
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int j = num.size() - 1;
        for(;j > 0; --j)
        {
            if(num[j] > num[j-1])
              break;
        }
        if(j > 0)
        {
            int k;
            for(k = num.size() -1; k >= j; --k)
            {
                if(num[k] > num[j - 1])
                  break;
            }
            int tmp;
            tmp = num[k];
            num[k] = num[j - 1];
            num[j - 1] = tmp;
        }
        int last = num.size() - 1;
        while(j < last)
        {
            int tmp; 
            tmp = num[j];
            num[j] = num[last];
            num[last] = tmp;
            ++j;
            --last;
        }
    }
};
