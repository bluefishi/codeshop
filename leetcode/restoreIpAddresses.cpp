//http://oj.leetcode.com/problems/restore-ip-addresses/
class Solution {
    public:
        vector<string> restoreIpAddresses(string s)
        {
            vector<string> ret;
            vector<int> lens(4, 0);
            restoreIPAddresses(s, lens, 0, 0, ret);
            return ret;
        }

        void restoreIPAddresses(const string& s, vector<int>& lens, int index, int start, vector<string>& ret)
        {
            if(index == 4)
            {
                int curLen = s.length() - start;
                if(curLen != 0)
                  return;
                int curStart = 0;
                ret.push_back("");
                for(int i = 0; i < 3; ++i)
                {
                    ret.back() += s.substr(curStart, lens[i]);
                    ret.back() += "."; 
                    curStart += lens[i];
                }
                ret.back() += s.substr(curStart, lens[3]);
                return;
            }
            if(start >= s.length())
              return;
            for(int i = 1; i <= min(3, (int)s.length() - start); ++i)
            {
                string snum = s.substr(start, i);
                if(i >= 2 && s[start] == '0')
                  break;
                istringstream is(snum);
                int mask = 0;
                is>>mask;
                if(mask >= 0 && mask <= 255)
                {
                    lens[index] = i ;
                    restoreIPAddresses(s, lens, index + 1, start + i, ret);
                }
            }
        }

};

