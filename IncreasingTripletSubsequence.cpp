#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int c1 = INT_MAX;
        int c2 = INT_MAX;

        for (int n : nums)
        {
            if (n <= c1)
                c1 = n;
            else if (n <= c2)
                c2 = n;
            else
                return true;
        }

        return false;
    }
};