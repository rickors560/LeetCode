#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int reachable = 0;
        int jumps = 0;
        int currentJumpEnd = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            reachable = max(reachable, i + nums[i]);

            if (currentJumpEnd == i)
            {
                jumps++;
                currentJumpEnd = reachable;
            }
        }

        return jumps;
    }
};