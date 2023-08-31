#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long result = 0;
        long long n = nums.size();

        long long lastSeen = nums[n - 1];

        for (long long i = n - 2; i >= 0; i--)
        {
            if (nums[i] > lastSeen)
            {
                long long partsToBreak = nums[i] / lastSeen;
                if (nums[i] % lastSeen > 0)
                    partsToBreak++;

                long long stepsNeededToBreak = partsToBreak - 1;

                lastSeen = nums[i] / partsToBreak;
                result += stepsNeededToBreak;
            }
            else
            {
                lastSeen = nums[i];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> x = {12, 9, 7, 6, 17, 19, 21};
    Solution s;
    s.minimumReplacement(x);
    return 0;
}