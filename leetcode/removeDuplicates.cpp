//http://leetcode.com/onlinejudge#question_26
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return n;
        int index = 1;
        int cur = A[0];
        for(int i = 1; i < n; ++i)
        {
            if(A[i] != cur)
            {
                A[index++] = A[i];
                cur = A[i];
            }
        }
        return index;
    }
};

