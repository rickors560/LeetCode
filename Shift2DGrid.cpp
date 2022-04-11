#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Hint : Method-1 -> Flat the grid and then do the rotations.
    // Hint : Method-2 -> Try to map flat array index to grid index without creating flat array.
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int flatIndex = i * m + j;
                flatIndex += k % (n * m);
                flatIndex %= (n * m);

                result[flatIndex / m][flatIndex % m] = grid[i][j];
            }
        }

        return result;
    }
};