//http://leetcode.com/onlinejudge#question_41
//虽然是交换，但不是简单的交换
//例如[-1,4,3,1]
//当扫描的4的时候，4和1交换，但这个时候不能继续往下扫描
//而是把1也放到自己的位置
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            while(A[i] >= 1 && A[i] <= n && A[i] != i + 1)
            {
                if(A[i] == A[A[i] - 1])
                  break;
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

