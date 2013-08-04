//http://leetcode.com/onlinejudge#question_66
//tmp 变量是个陷阱，如果不保存加之前的值，addtion和*it总归会有一个先被计算
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int addition = 1;
            int tmp;
            for(auto it = digits.rbegin(); it != digits.rend(); ++it)
            {
                tmp = *it;
                *it = (tmp + addition) % 10;
                addition = (tmp + addition) / 10;
            }
            if(addition)
              digits.insert(digits.begin(), addition);
            return digits;
        }
};

