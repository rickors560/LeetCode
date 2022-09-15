#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();

        if (n % 2 != 0)
            return {};

        unordered_map<int, int> lookUp;
        sort(changed.begin(), changed.end());

        for (int i = 0; i < n; i++)
            lookUp[changed[i]]++;

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (lookUp[changed[i]] == 0)
                continue;

            if (lookUp[changed[i] * 2] == 0)
                return {};

            result.push_back(changed[i]);
            lookUp[changed[i]]--;
            lookUp[changed[i] * 2]--;
        }

        return result;
    }
};