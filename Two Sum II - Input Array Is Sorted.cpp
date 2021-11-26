#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        vector<int> result;

        if (n < 2)
            return result;

        while (i < j)
        {
            int t = numbers[i] + numbers[j];

            if (t == target)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
            else if (t < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return result;
    }
};