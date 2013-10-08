//http://oj.leetcode.com/problems/sort-colors/
//use swap 
class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int zeroIndex = -1;
        int twoIndex = n;
        int i = 0;
        while(i < twoIndex)
        {
            if(A[i] == 0)
            {
                zeroIndex += 1;
                if(zeroIndex == i)
                  ++i;
                else
                {
                    int tmp = A[zeroIndex];
                    A[zeroIndex] = A[i];
                    A[i] = tmp;
                    if(A[i] == 1)
                      ++i;
                }
            }
            else if(A[i] == 2)
            {
                twoIndex -= 1;
                if(twoIndex == i)
                  ++i;
                else
                {
                    int tmp = A[twoIndex];
                    A[twoIndex] = A[i];
                    A[i] = tmp;
                    if(A[i] == 1)
                       ++i;
                }
            }
            else
            {
                ++i;
            }
        }
    }
};
