#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> columns;
    vector<bool> positiveDiagonals;
    vector<bool> negativeDiagonals;

    int backtrack(int row, int n)
    {
        if (row == n)
            return 1;
        int result = 0;

        for (int col = 0; col < n; col++)
        {
            if (columns[col] || positiveDiagonals[row - col + n] || negativeDiagonals[row + col])
                continue;

            columns[col] = true;
            positiveDiagonals[row - col + n] = true;
            negativeDiagonals[row + col] = true;
            result += backtrack(row + 1, n);
            columns[col] = false;
            positiveDiagonals[row - col + n] = false;
            negativeDiagonals[row + col] = false;
        }

        return result;
    }

public:
    int totalNQueens(int n)
    {
        columns = vector<bool>(n, false);
        positiveDiagonals = vector<bool>(2 * n - 1, false);
        negativeDiagonals = vector<bool>(2 * n - 1, false);

        return backtrack(0, n);
    }
};