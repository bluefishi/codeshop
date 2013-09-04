class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] >= 1 && A[i] <= n)
            {
                tmp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            }
        }
        int ret = 1;
        for(int i = 0; i < n; ++i, ++ret)
        {
            if(A[i] != ret)
              break;
        }
        return ret;
    }
};

