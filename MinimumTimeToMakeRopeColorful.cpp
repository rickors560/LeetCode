#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int totalTime = 0, n = neededTime.size();

        int left = 0, right = 0;

        while (left < n && right < n)
        {
            int currentTotal = 0;
            int currentMax = 0;

            while (right < n && colors[left] == colors[right])
            {
                currentMax = max(currentMax, neededTime[right]);
                currentTotal += neededTime[right++];
            }

            totalTime += currentTotal - currentMax;
            left = right;
        }

        return totalTime;
    }
};