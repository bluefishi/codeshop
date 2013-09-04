//http://leetcode.com/onlinejudge#question_32
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> lefts;
        int last = -1;
        int maxLen = 0;
        for(int i = 0; i < s.length(); ++i)
        {
           if(s[i] == '(')
             lefts.push(i);
           else
           {
               if(lefts.empty())
                 last = i;
               else
               {
                   lefts.pop();
                   if(lefts.empty())
                     maxLen = max(maxLen, i - last);
                   else
                     maxLen = max(maxLen, i - lefts.top());
               }
           }
        }
        return maxLen;
    }
};

