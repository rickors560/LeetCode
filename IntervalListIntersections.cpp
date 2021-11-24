#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList)
    {
        vector<vector<int>> ans;

        int n1 = firstList.size();
        int n2 = secondList.size();

        if (n1 == 0 || n2 == 0)
            return ans;

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2)
        {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);

            if (l <= r)
                ans.push_back({l, r});

            if (r == firstList[i][1])
                i++;
            if (r == secondList[j][1])
                j++;
        }

        return ans;
    }
};