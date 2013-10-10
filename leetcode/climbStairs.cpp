//http://oj.leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 1)
          return 1;
        int f_n_1 = 1;
        int f_n_2 = 1;
        int f_n;
        for(int i = 2; i <= n; ++i)
        {
            f_n = f_n_1 + f_n_2;
            f_n_1 =  f_n;
            f_n_2 = f_n_1;
        }
        cout<<f_n<<endl;
        return f_n;
    }
};

