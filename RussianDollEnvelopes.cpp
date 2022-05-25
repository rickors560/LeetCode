#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> envelopes)
    {
        auto comp = [](const vector<int> &a, const vector<int> &b)
        {
            if (a[0] == b[0])
                return b[1] < a[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> dp;

        for (auto envelop : envelopes)
        {
            int height = envelop[1];

            // position -> first position where height >= value of element at position ( Binary Search )
            int position = lower_bound(dp.begin(), dp.end(), height) - dp.begin();

            if (position == dp.size())
                dp.push_back(height);
            else
                dp[position] = height;
        }
        return dp.size();
    }
};
