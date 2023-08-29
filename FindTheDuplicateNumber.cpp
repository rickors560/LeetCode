#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Using Linked List Cycle Method in which
        // Two points - slow and fast collide would at
        //  x distance from duplicate number (cycle start point)
        //  and x will also be the distance from start of list to duplicate number
        int slow = 0;
        int fast = 0;

        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
            {
                break;
            }
        }

        // Now moving fast pointer to start and slow & fast pointers
        // would be at equal distance from duplicate number (Cycle Start Point)
        fast = 0;

        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
    }
};