#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using XOR
    int missingNumber1(vector<int> &nums)
    {
        int res = 0, i = 0; // a^b^b = a ->using xor property

        for (i = 0; i < nums.size(); i++)
        {
            res = res ^ i ^ nums[i];
        }
        return res ^ nums.size();
    }

    // Using sum
     int missingNumber2(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n+1)/2;

        for (int i = 0; i < nums.size(); i++)
        {
            sum -=  nums[i];
        }
        return sum;
    }
};