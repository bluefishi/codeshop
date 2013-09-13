//http://leetcode.com/onlinejudge#question_131
//搜索加剪枝
class Solution {
    public:
        vector<vector<string>> partition(string str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<string> > ret;
            if(str == "")
              return ret;
            int position = 1;
            vector<bool> choice(str.length());
            partition(choice, position, str, ret);
            return ret;

        }
        bool isValid(string& str, int left, int right)
        {
            while(left <= right)
            {
                if(str[left] != str[right])
                  return false;
                ++left;
                --right;
            }
            return true;
        }

        void partition(vector<bool>& choice, int position, string& str, vector<vector<string> >& ret)
        {
            if(position == str.length())
            {
                int left = position - 1;
                while(left >= 1 && !choice[left])
                  --left;
                if(isValid(str, left, position -1))
                {
                    ret.push_back(vector<string>());
                    int start = 0;
                    int end = 1;
                    while(end < str.length())
                    {
                        while(end < str.length() && !choice[end])
                          ++end;
                        ret.back().push_back(str.substr(start, end - start));
                        start = end;
                        ++end;
                    }
                    if(start < str.length())
                      ret.back().push_back(str.substr(start, end - start));
                }
                return;
            }

            int left = position - 1;
            while(left >= 1 && !choice[left])
              --left;
            if(isValid(str, left, position - 1))
            {
                choice[position] = true;
                partition(choice, position + 1, str, ret);
                choice[position] = false;
            }
            partition(choice, position + 1, str, ret);
        }

};

