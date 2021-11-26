#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        k = k % n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    void reverse(vector<int> &array, int start, int end)
    {
        int t = 0;
        while (start < end)
        {
            t = array[start];
            array[start] = array[end];
            array[end] = t;

            start++;
            end--;
        }
    }
};