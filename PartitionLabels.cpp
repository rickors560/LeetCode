#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int last[26] = {0};
        for (int i = 0; i < s.length(); i++)
            last[s[i] - 'a'] = i;

        vector<int> result;
        int startPartition = 0, endPartition = 0;
        for (int i = 0; i < s.length(); i++)
        {
            auto current = s[i] - 'a';
            endPartition = max(endPartition, last[current]);

            if (i == endPartition)
            {
                result.push_back(endPartition - startPartition + 1);
                startPartition = i + 1;
            }
        }

        return result;
    }
};