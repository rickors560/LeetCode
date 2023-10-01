#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int localProduct = 1;
        int globalProduct = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            localProduct *= nums[i];
            globalProduct = max(globalProduct, localProduct);

            if (localProduct == 0)
                localProduct = 1;
        }

        localProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            localProduct *= nums[i];
            globalProduct = max(globalProduct, localProduct);

            if (localProduct == 0)
                localProduct = 1;
        }

        return globalProduct;
    }
};