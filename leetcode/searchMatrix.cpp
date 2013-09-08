//http://leetcode.com/onlinejudge#question_74
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0)
          return false;
        int j = matrix[0].size() - 1;
        int i = 0;
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
              return true;
            else if(matrix[i][j] < target)
              i += 1;
            else
              j -= 1;
        }
        return false; 
    }
};
