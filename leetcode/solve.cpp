//http://leetcode.com/onlinejudge#question_130
//使用BFS，如果用DFS会调用栈层数太深
//可以不使用visited矩阵
//从边上的'O'出发，遇到的'O'置为'Y'
//最终剩余的'O'为被包围的，需要置为'X'
//'Y'置为'O'
class Solution {
    public:
        void solve(vector<vector<char> >& board)
        {
            if(board.size() == 0)
              return;
            if(board[0].size() == 0)
              return;
            queue<int> queRow;
            queue<int> queCol;
            int rows = board.size();
            int cols = board[0].size();
            for(int i = 0; i < rows; ++i)
            {
                if(board[i][0] == 'O')
                {
                    queRow.push(i);
                    queCol.push(0);
                }
                if(cols > 1 && board[i][cols - 1] == 'O')
                {
                    queRow.push(i);
                    queCol.push(cols - 1);
                }
            }

            for(int j = 1; j < cols - 1; ++j)
            {
                if(board[0][j] == 'O')
                {
                    queRow.push(0);
                    queCol.push(j);
                }
                if(rows > 1 && board[rows - 1][j] == 'O')
                {
                    queRow.push(rows - 1);
                    queCol.push(j);
                }
            }
            int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            while(!queRow.empty())
            {
                int parentx = queRow.front();
                int parenty = queCol.front();
                queRow.pop();
                queCol.pop();
                board[parentx][parenty] = 'Y';
                for(int i = 0; i < 4; ++i)
                {
                    int childx = parentx + dir[i][0];
                    int childy = parenty + dir[i][1];
                    if(childx >= 0 && childx < rows && childy >= 0 && childy < cols)
                    {
                        if(board[childx][childy] == 'O')
                        {
                            queRow.push(childx);
                            queCol.push(childy);
                        }
                    }
                }
            }
            for(int i = 0; i < rows; ++i)
            {
                for(int j = 0; j < cols; ++j)
                {
                    if(board[i][j] == 'Y')
                      board[i][j] = 'O';
                    else if(board[i][j] == 'O')
                      board[i][j] = 'X';
                }
            }
        }
};
