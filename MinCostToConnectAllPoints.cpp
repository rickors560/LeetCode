#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<bool> isVisited(n);

        minHeap.push({0, 0}); // Default cost 0, Default node 0,

        int totalCost = 0;
        int edgesUsed = 0;

        // edgesUsed => [ 0, n-1 ] for n nodes
        while (edgesUsed < n)
        {
            auto top = minHeap.top();
            minHeap.pop();

            int cost = top.first;
            int node = top.second;

            if (isVisited[node])
                continue;

            isVisited[node] = true;
            totalCost += cost;
            edgesUsed++;

            // Update Min Heap
            for (int i = 0; i < n; i++)
            {
                if (!isVisited[i])
                {
                    int nextCost = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    minHeap.push({nextCost, i});
                }
            }
        }

        return totalCost;
    }
};