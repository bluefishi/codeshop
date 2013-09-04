//http://leetcode.com/onlinejudge#question_31
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int upper = searchUpperBound(A, n, target);
        return upper;
    }

    int searchLowerBound(int A[], int n, int target)
    {
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(A[mid] < target)
              left = mid + 1;
            else
              right = mid;
        }
        if(A[left] > target)
          return left - 1;
        return left;
    }

    int searchUpperBound(int A[], int n, int target)
    {
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(A[mid] > target)
              right = mid - 1;
            else
              left = mid;
        }
        if(A[right] < target)
          return right + 1;
        return right;
    }
};

