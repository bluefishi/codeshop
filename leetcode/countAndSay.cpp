//http://leetcode.com/onlinejudge#question_38
class Solution {
    public:
        string countAndSay(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string count = "1";
            string say = count;
            int j = 0;
            char letter;
            int cl;
            for(int i = 1; i < n; ++i)
            {
                say = "";
                j = 0;
                cl = 1;
                letter = count[j];
                for(int k = 1; k < count.length(); ++k)
                {
                    if(count[k] != letter)
                    {
                        ostringstream os;
                        os<<cl<<letter;
                        say += os.str();
                        letter = count[k];
                        cl = 1;
                    }
                    else
                    {
                        cl += 1;
                    }
                }
                ostringstream os;
                os<<cl<<letter;
                say += os.str();
                count = say;
            }
            return say;
        }
};

