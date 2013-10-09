//http://oj.leetcode.com/problems/set-matrix-zeroes/
//use a zero row as extra space
class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int recordRow = -1;
            int rows = matrix.size();
            if(rows == 0)
              return;
            int cols = matrix[0].size();
            for(int i = 0; i < rows; ++i)
            {
                bool zero = false;
                for(int j = 0; j < cols; ++j)
                {
                    if(!matrix[i][j])
                    {
                        if(recordRow == -1)
                        {
                            recordRow = i;
                            for(int k = 0; k < cols; ++k)
                            {
                                matrix[i][k] = !matrix[i][k];
                            }
                            break;
                        }
                        else
                          matrix[recordRow][j] = 1;
                        zero = true;
                    }
                }
                if(zero && recordRow != i)
                {
                    for(int k = 0; k < cols; ++k)
                      matrix[i][k] = 0;
                }
            }
            if(recordRow != -1)
            {
                for(int j = 0; j < cols; ++j)
                {
                    if(matrix[recordRow][j])
                    {
                        for(int i = 0; i < rows; ++i)
                          matrix[i][j] = 0;
                    }
                }
                for(int j = 0; j < cols; ++j)
                  matrix[recordRow][j] = 0;
            }
        }
};

