#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> freq;
        priority_queue<int> maxHeap;

        for (auto a : arr)
            freq[a]++;

        for (auto [num, frq] : freq)
            maxHeap.push(frq);

        int result = 0;
        int deleted = 0;

        while (deleted < n / 2)
        {
            result++;
            deleted += maxHeap.top();
            maxHeap.pop();
        }

        return result;
    }
};