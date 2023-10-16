#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result = {1};

        for (int i = 0; i < rowIndex; i++)
        {
            int nextRowSize = result.size() + 1;
            vector<int> nextRow(nextRowSize, 0);

            for (int j = 0; j < result.size(); j++)
            {
                nextRow[j] += result[j];
                nextRow[j + 1] += result[j];
            }

            result = nextRow;
        }

        return result;
    }
};