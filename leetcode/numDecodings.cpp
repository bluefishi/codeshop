//http://oj.leetcode.com/problems/decode-ways/
//注意初始化f_n_1的时候需要判断s[0]
class Solution {
    public:
        int numDecodings(string s)
        {
            if(s.length() == 0)
              return 0;
            int f_n_2 = 1;
            int f_n_1; 
            if(s[0] != '0')
              f_n_1 = 1;
            else
              f_n_1 = 0;
            int f_n;
            for(int i = 2; i <= s.length(); ++i)
            {
                f_n = 0;
                if(s[i-1] != '0')
                  f_n += f_n_1;
                istringstream iscode(s.substr(i - 2, 2));
                int code = 0;
                iscode>>code;
                if(s[i-2] != '0' && code >= 1 && code <= 26)
                  f_n += f_n_2;
                f_n_2 = f_n_1;
                f_n_1 = f_n;
            }
            return f_n_1;
        }

};

