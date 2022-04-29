#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int n) : root(n), rank(n)
    {
        for (int i = 0; i < n; i++)
        {
            root[i] = i; // All nodes are root nodes.

            rank[i] = 1; // Default rank for all nodes is 1.
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;

        root[x] = find(root[x]); // To optimize for next calls, directly store root node to it.
        return root[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            int rankX = rank[x];
            int rankY = rank[y];

            if (rankX >= rankY)
            {
                root[rootY] = rootX; // Merging two disjoint sets

                rank[rootX] += rank[rootY]; // Updating the rank
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution
{
    static bool comp(const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
    {
        return p1.first < p2.first;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        UnionFind uf(n * m);

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + 1 < n)
                {
                    int x = abs(heights[i + 1][j] - heights[i][j]);     // Weight of the edge
                    edges.push_back({x, {i * m + j, (i + 1) * m + j}}); // i*m +j ==> Index of the vertex with two are connected for that weight of edge
                }

                if (j + 1 < m)
                {
                    int x = abs(heights[i][j + 1] - heights[i][j]);
                    edges.push_back({x, {i * m + j, i * m + j + 1}});
                }
            }
        }

        // Sort the edges by weights
        sort(
            edges.begin(), edges.end(),
            [](const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2) -> bool
            {
                return p1.first < p2.first;
            });

        int ans = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            auto edge = edges[i];
            auto x = edge.second.first;
            auto y = edge.second.second;

            // Union Set two vertices that connect edge
            uf.unionSet(x, y);

            // Check if top left and bottom right have same root, then top left and bottom right are connected and we have the ans
            if (uf.find(0) == uf.find(n * m - 1))
            {
                ans = edge.first;
                break;
            }
        }

        return ans;
    }
};