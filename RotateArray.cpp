#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // Intuition ->
        // Think of it like a matrix -> XY
        // In order to get -> YX, we do below operations
        // Transpose X = Trans(X) = X', Transpose Y = Trans(Y) = Y'
        // Now, Transpose of X'Y' = Trans(X'Y') = Trans(Y')Trans(X') = YX

        int n = nums.size();

        k = k % n;
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};