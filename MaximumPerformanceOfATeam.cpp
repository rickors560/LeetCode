#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1000000007;

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> players;

        for (int i = 0; i < n; i++)
            players.push_back({efficiency[i], speed[i]});

        auto comp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
        {
            return b.first < a.first;
        };

        // Sorting players on decreasing order of efficiency
        sort(players.begin(), players.end(), comp);

        long long totalSpeed = 0;
        long long totalPerformance = 0;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++)
        {
            // Will always be minimum efficiency as players are sorted in decreasing order
            int currentEfficiency = players[i].first;
            int currentSpeed = players[i].second;

            if (minHeap.size() == k)
            {
                totalSpeed -= minHeap.top(); // Removing min speed
                minHeap.pop();
            }

            minHeap.push(currentSpeed);
            totalSpeed += currentSpeed;
            totalPerformance = max(totalPerformance, totalSpeed * currentEfficiency);
        }

        return totalPerformance % MOD;
    }
};