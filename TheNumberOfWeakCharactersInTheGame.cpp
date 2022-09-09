#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        auto comp = [](const vector<int> &a, const vector<int> &b) -> bool
        {
            // true means 'a' go in front of 'b' while sort (General concept in c++)
            if (a[0] == b[0]) // Both have same attack value
                return a[1] < b[1];
            return a[0] > b[0];
        };

        sort(properties.begin(), properties.end(), comp);

        int result = 0;
        int maxDefense = INT_MIN;

        for (auto prop : properties)
        {
            if (maxDefense > prop[1])
                result++;
            else
                maxDefense = prop[1];
        }

        return result;
    }
};