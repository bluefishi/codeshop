//http://leetcode.com/onlinejudge#question_72
//O(m+n) space complexity
//O(m*n) time comlexity
class Solution {
    public:
        int minDistance(string s1, string s2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> f(s2.length() + 1);
            for(int j = 0; j <= s2.length(); ++j)
            {
                f[j] = j;
            }
            int fi_1_j_1;
            int tmp;
            for(int i = 1; i <= s1.length(); ++i)
            {
                f[0] = i;
                fi_1_j_1 = i - 1;
                for(int j = 1; j <= s2.length(); ++j)
                {
                    tmp = f[j];//save fi_1_j_1
                    if(s1[i - 1] == s2[j - 1])
                    {
                        f[j] = fi_1_j_1;
                    }
                    else
                    {
                        f[j] = min(fi_1_j_1, f[j]);
                        f[j] = min(f[j], f[j-1]);
                        f[j] += 1;
                    }
                    fi_1_j_1 = tmp;
                }	
            }
            return f[s2.length()];
        }
};

