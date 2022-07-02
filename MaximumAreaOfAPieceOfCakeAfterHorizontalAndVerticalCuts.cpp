#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1000000007;

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int previousCut = 0;

        horizontalCuts.push_back(h);
        long int maxHeight = 0;
        for (int i = 0; i < horizontalCuts.size(); i++)
        {
            maxHeight = max(maxHeight, (long)horizontalCuts[i] - previousCut);
            previousCut = horizontalCuts[i];
        }

        previousCut = 0;

        verticalCuts.push_back(w);
        long int maxWidth = 0;
        for (int i = 0; i < verticalCuts.size(); i++)
        {
            maxWidth = max(maxWidth, (long)verticalCuts[i] - previousCut);
            previousCut = verticalCuts[i];
        }

        return (maxHeight * maxWidth) % MOD;
    }
};