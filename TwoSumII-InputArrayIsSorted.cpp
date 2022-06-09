#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        int n = numbers.size();

        if (n < 2)
            return result;

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int t = numbers[l] + numbers[r];

            if (t == target)
            {
                result = {l, r};
                return result;
            }

            if (t < target)
                l++;
            else
                r--;
        }

        return result;
    }
};