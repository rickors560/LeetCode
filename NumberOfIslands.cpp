#include <bits/stdc++.h>
using namespace std;

//----------------------------< Using BFS >----------------------------

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int answer = 0;

        vector<vector<bool>> visited(m, vector<bool>(n));

        vector<pair<int, int>> directions = {{1, 0},
                                             {0, 1},
                                             {-1, 0},
                                             {0, -1}};

        auto isInside = [m, n](const int x, const int y)
        {
            return x >= 0 && y >= 0 && x < m && y < n;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    answer++;

                    // bfs
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto [d1, d2] : directions)
                        {
                            int row = x + d1;
                            int col = y + d2;

                            if (isInside(row, col) && !visited[row][col] && grid[row][col] == '1')
                            {
                                q.push({row, col});
                                visited[row][col] = true;
                            }
                        }
                    }
                }
            }
        }

        return answer;
    }
};

//----------------------------< Using Union Find >----------------------------

class UnionFind
{
    vector<int> parent;
    int totalGroups = 0;

public:
    UnionFind(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        parent = vector<int>(m * n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    parent[i * n + j] = i * n + j; //<i*n + j> => flatting 2D index
                    totalGroups++;
                }
            }
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX != parentY)
        {
            parent[parentX] = parentY;
            totalGroups--;
        }
    }

    int getTotalGroups()
    {
        return totalGroups;
    }
};

class Solution1
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        UnionFind uf(grid);

        vector<pair<int, int>> directions = {{1, 0},
                                             {0, 1},
                                             {-1, 0},
                                             {0, -1}};

        auto isInside = [m, n](const int x, const int y)
        {
            return x >= 0 && y >= 0 && x < m && y < n;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    int index1 = i * n + j;

                    for (auto [d1, d2] : directions)
                    {
                        int row = i + d1;
                        int col = j + d2;
                        int index2 = row * n + col;

                        if (isInside(row, col) && grid[row][col] == '1')
                            uf.unionSet(index1, index2); // Grouping to same group
                    }
                }
            }
        }

        return uf.getTotalGroups();
    }
};