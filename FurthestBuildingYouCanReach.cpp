#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int i = 0; i < heights.size() - 1; i++)
        {
            int d = heights[i + 1] - heights[i];

            if (d > 0) // First use all ladder and push in min heap
                pq.push(d);

            if (pq.size() > ladders) // We have used all the ladders, then swap smallest ladder with bricks
            {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0)
                return i;
        }

        return heights.size() - 1;
    }
};