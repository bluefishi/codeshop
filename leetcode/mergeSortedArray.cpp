//http://leetcode.com/onlinejudge#question_88
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = m + n - 1;
        int m1 = m - 1;
        int n1= n - 1;
        while(m1 >= 0 && n1 >= 0)
        {
            if(A[m1] > B[n1])
            {
                A[l] = A[m1];
                m1 -= 1;
            }
            else
            {
                A[l] = B[n1];
                n1 -= 1;
            }
            l -= 1;
        }
        while(n1 >= 0)
        {
            A[l] = B[n1];
            n1 -= 1;
            l -= 1;
        }
    }
};

