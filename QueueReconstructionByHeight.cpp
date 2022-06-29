#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        auto compare = [](const vector<int> &a, const vector<int> &b) -> bool
        {
            // If two persons have same height, then we sort on the basis increasing no. of people in-front of them
            // else we sort on the basis on decreasing height (Max height first)
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] > b[0]);
        };

        sort(people.begin(), people.end(), compare);

        vector<vector<int>> result;

        for (auto person : people)
        {
            int index = person[1];
            result.insert(people.begin() + index, person);
        }

        return result;
    }
};