#include <bits/stdc++.h>

using namespace std;

class Solution
{
    // To prevent negative modulo(%)
    int floorMod(int x, int y)
    {
        return ((x % y) + y) % y;
    }

public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));

        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentDirection = 0;

        int count = 0;

        int row = 0, col = 0;

        while (count < n * n)
        {
            matrix[row][col] = count++;

            int nextRow = floorMod(row + direction[currentDirection][0], n);
            int nextCol = floorMod(col + direction[currentDirection][1], n);

            // If next value is not 0 (default initialized i.e., next block is already filled)
            if (matrix[nextRow][nextCol] != 0)
            {
                currentDirection = (currentDirection + 1) % 4;
            }

            row += direction[currentDirection][0];
            col += direction[currentDirection][1];
        }

        return matrix;
    }
};