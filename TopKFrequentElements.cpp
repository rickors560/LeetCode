#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Using Heap
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequency;
        for (auto num : nums)
        {
            frequency[num]++;
        }

        auto comparator = [&frequency](int a, int b)
        {
            return frequency[a] < frequency[b];
        };
        priority_queue<int, vector<int>, decltype(comparator)> queue(comparator);

        for (pair<int, int> entry : frequency)
        {
            queue.push(entry.first);
        }

        vector<int> ans;
        while (k > 0)
        {
            ans.push_back(queue.top());
            queue.pop();
            k--;
        }

        return ans;
    }
};