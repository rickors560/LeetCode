#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;

        int n = grid.size();
        int m = grid[0].size();
        int directions[][2] = {{0, 1},
                               {1, 0},
                               {0, -1},
                               {-1, 0},
                               {1, 1},
                               {1, -1},
                               {-1, 1},
                               {-1, -1}};

        queue<vector<int>> q;

        q.push({0, 0, 1}); // Initial x,y, distance
        grid[0][0] = 1;

        while (!q.empty())
        {
            int size = q.size();
            while (size > 0)
            {
                auto point = q.front();
                q.pop();

                if (point[0] == n - 1 && point[1] == m - 1)
                    return point[2];

                for (auto dir : directions)
                {
                    int r = dir[0] + point[0];
                    int c = dir[1] + point[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 0)
                    {
                        q.push({r, c, point[2] + 1});
                        grid[r][c] = 1; // Set point as visited
                    }
                }

                size--;
            }
        }

        return -1;
    }
};