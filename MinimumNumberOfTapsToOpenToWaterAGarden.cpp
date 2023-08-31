#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        int left = 0;
        int right = 0;
        int taps = 0;
        int lastTapIndex = 0;

        while (right < n)
        {
            for (int i = lastTapIndex; i < ranges.size(); i++)
            {
                if (i - ranges[i] <= left && i + ranges[i] >= right)
                {
                    right = i + ranges[i];
                    lastTapIndex = i;
                }
            }

            int areaCovered = right - left;
            if (areaCovered <= 0)
                return -1;

            left = right;
            taps++;
        }

        return taps;
    }
};