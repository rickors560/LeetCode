#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum rectangle-wise
class NumMatrix
{
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        prefixSum = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));

        for (int i = 1; i <= r; i++)
        {
            int sum = 0;
            for (int j = 1; j <= c; j++)
            {
                sum += matrix[i - 1][j - 1];
                int aboveRow = prefixSum[i - 1][j];
                prefixSum[i][j] = sum + aboveRow;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int bottom = prefixSum[row2 + 1][col2 + 1];
        int left = prefixSum[row2 + 1][col1];
        int top = prefixSum[row1][col2 + 1];
        int topLeft = prefixSum[row1][col1];
        return bottom - left - top + topLeft;
    }
};

// Using Prefix Sum row-wise
class NumMatrix1
{
    vector<vector<int>> prefixSum;

public:
    NumMatrix1(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        prefixSum = vector<vector<int>>(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            prefixSum[i][0] = matrix[i][0];
            for (int j = 1; j < c; j++)
            {
                prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int result = 0;
        for (int r = row1; r <= row2; r++)
        {
            result += prefixSum[r][col2] - (col1 > 0 ? prefixSum[r][col1 - 1] : 0);
        }
        return result;
    }
};