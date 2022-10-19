#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;

        for (auto word : words)
            freq[word]++;

        auto comp = [](pair<string, int> &a, pair<string, int> &b) -> bool
        {
            return a.second == b.second ? a.first.compare(b.first) < 0 : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);

        for (auto [key, value] : freq)
        {
            pq.push({key, value});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> result(k);
        int i = k - 1;
        while (!pq.empty())
        {
            result[i] = pq.top().first;
            pq.pop();

            i--;
        }

        return result;
    }
};