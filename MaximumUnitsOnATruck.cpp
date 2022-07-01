#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        auto comp = [](const vector<int> &a, const vector<int> &b) -> bool
        {
            return b[1] < a[1];
        };

        sort(boxTypes.begin(), boxTypes.end(), comp);

        int result = 0;

        for (auto box : boxTypes)
        {
            if (truckSize <= 0)
                break;

            result += min(truckSize, box[0]) * box[1];
            truckSize -= box[0];
        }

        return result;
    }
};