#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> data;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        // Will always be sorted as it is time based
        data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (data.find(key) == data.end() || data[key][0].first > timestamp)
            return "";

        int left = 0;
        int right = data[key].size() - 1;

        string result;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (data[key][mid].first <= timestamp)
            {
                result = data[key][mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};