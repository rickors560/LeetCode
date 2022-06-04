#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> columns;
    vector<bool> positiveDiagonals;
    vector<bool> negativeDiagonals;

public:
    // Valid moves for a queen are vertical, horizontal and diagonals (both positive and negative)

    vector<vector<string>> solveNQueens(int n)
    {
        columns = vector<bool>(n, 0);                         // Flag for columns
        positiveDiagonals = vector<bool>((2 * n) - 1, false); // Positive diagonals as (row-col) will always be constant for a diagonal
        negativeDiagonals = vector<bool>((2 * n) - 1, false); // Negative diagonals as (row+col) will always be constant for a diagonal

        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        backTrack(n, 0, result, board);

        return result;
    }

    void backTrack(int &n, int row, vector<vector<string>> &result, vector<string> &board)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            // If column or diagonals are preoccupied we skip that col.
            // row - col + n cause row-col can be negative so we add n to make it in bounds.
            if (columns[col] || positiveDiagonals[row - col + n] || negativeDiagonals[row + col])
                continue;

            columns[col] = true;
            positiveDiagonals[row - col + n] = true;
            negativeDiagonals[row + col] = true;
            board[row][col] = 'Q';

            backTrack(n, row + 1, result, board);

            columns[col] = false;
            positiveDiagonals[row - col + n] = false;
            negativeDiagonals[row + col] = false;
            board[row][col] = '.';
        }
    }
};