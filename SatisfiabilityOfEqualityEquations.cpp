#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    int nodes[26];

public:
    UnionFind()
    {
        for (int i = 0; i < 26; i++)
            nodes[i] = i;
    }

    int find(int x)
    {
        if (nodes[x] != x)
            nodes[x] = find(nodes[x]);
        return nodes[x];
    }

    void unionNodes(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX != parentY)
            nodes[parentY] = parentX;
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind uf;

        for (string eq : equations)
            if (eq[1] == '=')
                uf.unionNodes(eq[0] - 'a', eq[3] - 'a');

        for (string eq : equations)
            if (eq[1] == '!')
                if (uf.find(eq[0] - 'a') == uf.find(eq[3] - 'a'))
                    return false;

        return true;
    }
};