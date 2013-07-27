//http://leetcode.com/onlinejudge#question_50
//time complexity O(bitof(int))
class Solution {
    public:
        double pow(double x, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            unsigned n1 = 0;
            if(n >= 0)
              n1 = n;
            else
              n1 = -n;
            double ret = 1;
            double cur = x;
            while(n1)
            {
                if(n1 & 1)
                {
                    if(n >= 0)
                      ret *= cur;
                    else
                      ret /= cur;
                }
                cur *= cur;
                n1 >>= 1;
            }
            return ret;
        }
};

