#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        // We have only 1-6 values and we store their frequency
        int a[7] = {0};
        int b[7] = {0};
        int same[7] = {0};

        for (int i = 0; i < tops.size(); i++)
        {
            a[tops[i]]++;
            b[bottoms[i]]++;

            if (tops[i] == bottoms[i])
                same[tops[i]]++;
        }

        for (int i = 1; i <= 6; i++)
        {
            // If frequency of i in Tops + frequency of i in Bottoms - frequency at overlapping positions == n then the its possible.
            if (a[i] + b[i] - same[i] == tops.size())
            {
                return min(a[i], b[i]) - same[i];
            }
        }

        return -1;
    }
};