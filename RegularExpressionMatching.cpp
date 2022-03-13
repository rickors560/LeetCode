#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return dfs(s, p, 0, 0);
    }

private:
    map<pair<int, int>, bool> cache;

    bool dfs(string &s, string &p, int i, int j)
    {
        if (cache.find({i, j}) != cache.end())
        {
            return cache[{i, j}];
        }
        if (i >= s.size() && j >= p.size())
        {
            return true;
        }

        if (j >= p.size())
        {
            return false;
        }

        bool match = false;

        if (i < s.size())
        {
            match = ((s[i] == p[j]) || (p[j] == '.'));
        }

        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            bool temp = dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
            cache.insert({{i, j}, dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j))});
            return temp;
        }

        if (match)
        {
            bool temp = dfs(s, p, i + 1, j + 1);
            cache.insert({{i, j}, temp});
            return temp;
        }
        return false;
    }
};