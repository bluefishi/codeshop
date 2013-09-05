class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        int** memo = new int*[s1.length() + 1];
        for(int i = 0; i < s1.length() + 1; ++i)
        {
            memo[i] = new int[s2.length() + 1];
            memset(memo[i], -1, sizeof(int)*(s2.length() + 1));
        }
        if(len1 + len2 != len3)
          return false;
        isInterleave(s1, s1.length(), s2, s2.length(), s3, memo);
        bool ret = memo[len1][len2] == 1;
        for(int i = 0; i < s1.length() + 1; ++i)
          delete [](memo[i]);
        delete []memo;
        return ret;
    }
    
    int isInterleave(const string& s1, int len1 , const string& s2, int len2, const string& s3, int** memo)
    {
        if(memo[len1][len2] != -1)
          return memo[len1][len2];
        if(len1 == 0 && len2 == 0)
        {
            memo[len1][len2] = 1;
            return 1;
        }
        if(len1 > 0 &&  s1[len1 - 1] == s3[len1 + len2 -1])
        {
            if(isInterleave(s1, len1 - 1, s2, len2, s3, memo))
            {
                memo[len1][len2] = 1;
                return 1;
            }
        }
        if(len2 > 0 && s2[len2 - 1] == s3[len1 + len2 - 1])
        {
            if(isInterleave(s1, len1, s2, len2 - 1, s3, memo))
            {
                memo[len1][len2] = 1;
                return 1;
            }
        }
        memo[len1][len2] = 0;
        return 0;
    }

};

