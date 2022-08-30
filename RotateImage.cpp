#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void reverseRows(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reverseRows(matrix);
    }

    void rotate1(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        while (left < right && top < bottom)
        {
            // For row of size n, we are only transitioning n-1 elements
            for (int i = 0; i < right - left; i++)
            {
                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }

            left++;
            right--;
            top++;
            bottom--;
        }
    }
};