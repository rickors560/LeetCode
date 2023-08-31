#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        auto comparator = [](vector<int> &a, vector<int> &b) -> bool
        {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comparator);

        int start, end;
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); i++)
        {
            start = intervals[i][0];
            end = intervals[i][1];

            while (i + 1 < intervals.size() && end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            result.push_back({start, end});
        }

        return result;
    }
};