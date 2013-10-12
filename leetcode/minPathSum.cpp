//http://oj.leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rows = grid.size();
        if(rows == 0)
          return 0;
        int cols = grid[0].size();
        if(cols == 0)
          return 0;
        vector<vector<int> > dist(rows, vector<int>(cols, 0x7fffffff));
        dist[0][0] = grid[0][0];
        int line = 1;
        for(int i = 0; i < rows; ++i)
        {
            int rowIndex = i;
            int colIndex = 0;
            while(rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols)
            {
                if(colIndex + 1 < cols)
                {
                    if(dist[rowIndex][colIndex] + grid[rowIndex][colIndex + 1] < dist[rowIndex][colIndex + 1])
                      dist[rowIndex][colIndex + 1] = dist[rowIndex][colIndex] + grid[rowIndex][colIndex + 1];
                }
                if(rowIndex + 1 < rows)
                {
                    if(dist[rowIndex][colIndex] + grid[rowIndex + 1][colIndex] < dist[rowIndex + 1][colIndex])
                      dist[rowIndex + 1][colIndex] = dist[rowIndex][colIndex] + grid[rowIndex + 1][colIndex];
                }
                --rowIndex;
                ++colIndex;
            }
        }
        for(int i = 1; i < cols; ++i)
        {
            int rowIndex = rows - 1;
            int colIndex = i;
            while(rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols)
            {
                if(colIndex + 1 < cols)
                {
                    if(dist[rowIndex][colIndex] + grid[rowIndex][colIndex + 1] < dist[rowIndex][colIndex + 1])
                      dist[rowIndex][colIndex + 1] = dist[rowIndex][colIndex] + grid[rowIndex][colIndex + 1];
                }
                if(rowIndex + 1 < rows)
                {
                    if(dist[rowIndex][colIndex] + grid[rowIndex + 1][colIndex] < dist[rowIndex + 1][colIndex])
                      dist[rowIndex + 1][colIndex] = dist[rowIndex][colIndex] + grid[rowIndex + 1][colIndex];
                }
                --rowIndex;
                ++colIndex;
            }
        }
        return dist[rows - 1][cols - 1];
    }
};
