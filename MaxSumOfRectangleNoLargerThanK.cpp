#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Find the max sub array no more than K (Kadane's algo)
    int findMaxSum(vector<int> &sum, int k)
    {
        int result = INT_MIN;

        set<int> bst;
        bst.insert(0);

        int prefixSum = 0;

        for (int i = 0; i < sum.size(); i++)
        {
            prefixSum += sum[i];

            auto target = bst.lower_bound(prefixSum - k);

            if (target != bst.end())
                result = max(result, prefixSum - *target);

            bst.insert(prefixSum);
        }

        return result;
    }

public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int result = INT_MIN;

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            vector<int> sum(col, 0);

            for (int r = i; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                    sum[c] += matrix[r][c];

                result = max(result, findMaxSum(sum, k));
            }
        }

        return result;
    }
};