#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagonals;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int diagonalKey = i - j; // as for all diagonal (left -> right) i-j remains constant
                diagonals[diagonalKey].push(mat[i][j]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int diagonalKey = i - j;
                mat[i][j] = diagonals[diagonalKey].top();
                diagonals[diagonalKey].pop();
            }
        }

        return mat;
    }
};