//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(int a[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int index = 0;        
        int i = 0;
        while(i < n)
        {
            int ibackup = i;
            while(i < n && a[i] == a[ibackup])
              ++i;
            int count = min(i - ibackup, 2);
            for(int j = 0; j < count; ++j)
              a[index++] = a[ibackup];
        }
        return index;
    }
};

