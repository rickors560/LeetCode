#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (startFuel >= target)
            return 0;

        priority_queue<int> maxHeap;

        int stops = 0;
        int distance = startFuel;

        int currentStation = 0;
        int n = stations.size();

        while (distance < target)
        {
            while (currentStation < n && stations[currentStation][0] <= distance)
            {
                maxHeap.push(stations[currentStation++][1]); // Adding fuels on stations in between the path.
            }

            if (maxHeap.empty())
                return -1;

            distance += maxHeap.top(); // Getting max fuel
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};