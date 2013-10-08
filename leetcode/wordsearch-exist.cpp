//http://oj.leetcode.com/problems/word-search/
class Solution {
    private:
        int indicator;
        struct Point
        {
            int x;
            int y;
            Point(int px, int py)
                :x(px), y(py)
            {
            }
        };
    private:
        bool exist(const vector<vector<char> >& board, vector<vector<int> >& visited, int row, int col, int index, const string& word)
        {
            visited[row][col] = indicator;
            if(index == word.length())
              return true;
            Point dir[4] = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
            for(int i = 0; i < 4; ++i)
            {
                int nrow = row + dir[i].x;
                int ncol = col + dir[i].y;
                if(nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size()
                            && board[nrow][ncol] == word[index] && visited[nrow][ncol] != indicator)
                {
                    if(exist(board, visited, nrow, ncol, index + 1, word))
                      return true;
                }
            }
            visited[row][col] = indicator - 1;
            return false;
        }

    public:
        bool exist(vector<vector<char> > &board, string word) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(word.length() == 0)
              return true;
            indicator = 1;
            int rows = board.size();
            if(rows == 0)
              return false;
            int cols = board[0].size();
            vector<vector<int> > visited(rows, vector<int>(cols, indicator - 1));
            for(int i = 0; i < rows; ++i)
            {
                for(int j = 0; j < cols; ++j)
                {
                    if(board[i][j] == word[0])
                    {
                        if(exist(board, visited, i, j, 1, word))
                          return true;
                        ++indicator;
                    }
                }
            }
            return false;

        }
};

