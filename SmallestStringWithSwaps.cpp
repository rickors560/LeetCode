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
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        UnionFind uf(s.size());

        for (auto edge : pairs)
        {
            int source = edge[0];
            int destination = edge[1];

            uf.unionSet(source, destination);
        }

        unordered_map<int, vector<int>> rootToGroups;

        for (int vertex = 0; vertex < s.size(); vertex++)
        {
            int root = uf.find(vertex);

            rootToGroups[root].push_back(vertex);
        }

        string result(s.size(), ' ');

        for (auto entrySet : rootToGroups)
        {
            auto group = entrySet.second;

            vector<char> characters;
            for (int index : group)
            {
                characters.push_back(s[index]);
            }
            sort(characters.begin(), characters.end());

            for (int i = 0; i < group.size(); i++)
            {
                result[group[i]] = characters[i];
            }
        }

        return result;
    }
};