#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1;
        int count = 1;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] == nums[j - 1])
            {
                if (count < 2)
                {
                    count++;
                    nums[i] = nums[j];
                    i++;
                }
            }
            else
            {
                count = 1;
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

int main()
{
    vector<int> x = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution s;
    s.removeDuplicates(x);
    return 0;
}