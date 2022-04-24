#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem
{
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, vector<int>> totalCheckouts;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto passengerIn = checkIns[id];
        auto startStation = passengerIn.first;
        auto startTime = passengerIn.second;

        totalCheckouts[startStation + "-" + stationName].push_back(t - startTime);
    }

    double getAverageTime(string startStation, string endStation)
    {
        auto checkouts = totalCheckouts[startStation + "-" + endStation];
        return accumulate(checkouts.begin(), checkouts.end(), 0.0) / checkouts.size();
    }
};