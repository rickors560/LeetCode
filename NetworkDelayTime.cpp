#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Dijkstra Algorithm
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adjacent;

        for (auto time : times)
        {
            adjacent[time[0]].push_back({time[2], time[1]}); // source -> [ { time, destination } ]
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> signalReceivedAt(n + 1, INT_MAX); // Default INT_MAX as signal is not reached

        minHeap.push({0, k});
        signalReceivedAt[k] = 0;

        while (!minHeap.empty())
        {
            auto currentNodeTime = minHeap.top().first;
            auto currentNode = minHeap.top().second;
            minHeap.pop();

            if (currentNodeTime > signalReceivedAt[currentNode])
                continue;

            for (auto neighborNode : adjacent[currentNode])
            {
                auto neighborNodeTime = neighborNode.first + currentNodeTime;
                auto node = neighborNode.second;

                if (neighborNodeTime < signalReceivedAt[node])
                {
                    signalReceivedAt[node] = neighborNodeTime;
                    minHeap.push({neighborNodeTime, node});
                }
            }
        }

        int result = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            result = max(result, signalReceivedAt[i]);
        }

        return result != INT_MAX ? result : -1;
    }
};