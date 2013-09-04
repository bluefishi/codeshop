//http://leetcode.com/onlinejudge#question_34
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lower = searchLowerBound(A, n, target);        
        int upper = searchUpperBound(A, n, target);
        vector<int> ret;
        if(lower < 0 || upper >= n)
        {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else if(A[lower] != A[upper])
        {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else
        {
            ret.push_back(lower);
            ret.push_back(upper);
        }
        return ret;
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

