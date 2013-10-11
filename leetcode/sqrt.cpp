//binary search lowwer bound of sqrt(x) from 1...n
//note mid = left + (right - left) / 2 in case of overflow
class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(x == 0)
          return 0;
        int left = 1;
        int right = x;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(x / mid > mid)
              left = mid + 1;
            else
              right = mid;
        }
        if(x / left < left)
          return left - 1;
        return left;
    }
};

