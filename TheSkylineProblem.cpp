#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> heights;

        for (auto building : buildings)
        {
            heights.push_back({building[0], -building[2]}); // Start of building
            heights.push_back({building[1], building[2]});  // End of building
        }

        sort(heights.begin(), heights.end()); // Based on x if x is same then based on y

        vector<vector<int>> result;
        multiset<int> maxHeap;

        maxHeap.insert(0);
        int prev = 0;

        for (auto height : heights)
        {
            if (height.second < 0)
                maxHeap.insert(-height.second);
            else
                maxHeap.erase(maxHeap.find(height.second));

            if (prev != *maxHeap.rbegin())
                result.push_back({height.first, prev = *maxHeap.rbegin()});
        }

        return result;
    }
};
