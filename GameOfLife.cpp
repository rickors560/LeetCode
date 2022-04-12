#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int getLiveNeighborsCount(vector<vector<int>> board, int row, int col)
    {
        int m = board.size(), n = board[0].size();

        int count = 0;

        count += (col - 1 >= 0) ? board[row][col - 1] : 0;
        count += (col + 1 < n) ? board[row][col + 1] : 0;

        count += (row - 1 >= 0) ? board[row - 1][col] : 0;
        count += (row + 1 < m) ? board[row + 1][col] : 0;

        count += (row - 1 >= 0 && col - 1 >= 0) ? board[row - 1][col - 1] : 0;
        count += (row + 1 < m && col + 1 < n) ? board[row + 1][col + 1] : 0;

        count += (row - 1 >= 0 && col + 1 < n) ? board[row - 1][col + 1] : 0;
        count += (row + 1 < m && col - 1 >= 0) ? board[row + 1][col - 1] : 0;

        return count;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> tempBoard(board);

        int m = board.size(), n = board[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int liveNeighborsCount = getLiveNeighborsCount(tempBoard, r, c);

                if (tempBoard[r][c])
                {
                    board[r][c] = (liveNeighborsCount == 2 || liveNeighborsCount == 3) ? 1 : 0;
                }
                else
                {
                    board[r][c] = liveNeighborsCount == 3 ? 1 : 0;
                }
            }
        }
    }
};