//http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
//当a[l] <= a[m]时，不能简单的认为l...m是非递减序列
//首先a[l] <= a[m] =>l...m为非递减序列 
//a[l] == a[m] && l == m =>l...m为非递减序列
//a[l] == a[m] && l!=m 无法确定l...m为非递减序列，需要从l...u中扫描
class Solution {
    public:
        bool search(int a[], int l, int u, int x) {
            while (l <= u) 
            {
                int m = (l + u) / 2;
                if (x == a[m])
                  return true;
                else if (a[l] <= a[m]) 
                {
                    if(a[l] == a[m] && l != m)
                    {
                        return find(a+l, a+u+1, x) != a+u+1;
                    }
                    if (x > a[m]) 
                      l = m+1;
                    else if (x >=a [l]) 
                      u = m-1;
                    else 
                      l = m+1;
                }
                else if (x < a[m]) 
                  u = m-1;
                else if (x <= a[u]) 
                  l = m+1;
                else 
                  u = m - 1;
            }
            return false;
        }
        bool search(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return search(A, 0, n - 1, target);

        }
};

