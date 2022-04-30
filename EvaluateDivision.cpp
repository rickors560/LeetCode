#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    unordered_map<string, pair<string, double>> root;

public:
    pair<string, double> find(string x)
    {
        if (root.count(x) == 0)
        {
            root[x] = {x, 1};
        }

        if (root[x].first == x)
        {
            return root[x];
        }

        auto parent = find(root[x].first);

        root[x].first = parent.first;
        root[x].second *= parent.second;

        return root[x];
    }

    void unionSet(string x, string y, double value)
    {
        auto rootX = find(x);
        auto rootY = find(y);

        if (rootX.first != rootY.first)
        {
            root[rootY.first].first = rootX.first;
            root[rootY.first].second = (rootX.second / (rootY.second * value));
        }
    }

    bool isValid(string x)
    {
        return root.count(x) > 0;
    }
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        UnionFind uf;

        for (int i = 0; i < equations.size(); i++)
        {
            uf.unionSet(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> answers;

        for (auto query : queries)
        {
            if (!uf.isValid(query[0]) || !uf.isValid(query[1]))
                answers.push_back(-1);

            else
            {
                auto x = uf.find(query[0]);
                auto y = uf.find(query[1]);

                if (x.first != y.first)
                    answers.push_back(-1);

                else
                {
                    auto r = x.second / y.second;
                    answers.push_back(r);
                }
            }
        }

        return answers;
    }
};