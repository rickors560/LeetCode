#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> cardPoints, int k)
    {
        int n = cardPoints.size();

        int sum = 0;

        int left = k - 1;
        int right = n - 1;

        for (int i = 0; i < k; i++)
            sum += cardPoints[i];

        int result = sum;

        while (k--)
        {
            sum -= cardPoints[left--];
            sum += cardPoints[right--];

            result = max(result, sum);
        }

        return result;
    }
};