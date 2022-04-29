#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int n) : root(n), rank(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            root[i] = i;
        }
    }

    int find(int x)
    {
        if (root[x] == x)
        {
            return x;
        }
        root[x] = find(root[x]);
        return root[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            int rankX = rank[rootX];
            int rankY = rank[rootY];

            if (rankX >= rankY)
            {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
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
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        UnionFind uf(n);

        for (int i = 0; i < n; i++)
        {
            for (int j : graph[i])
            {
                if (uf.find(i) == uf.find(j))
                    return false;
                uf.unionSet(graph[i][0], j);
            }
        }
        return true;
    }
};