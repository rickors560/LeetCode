#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
    // store no. of events at the same time, until the next time point
    map<int, int> events; // Ordered map
    int result = 0;

    void insert(int time)
    {
        auto prev = --events.upper_bound(time);
        events[time] = prev->second; // Setting no. of events to prev event count
    }

public:
    MyCalendarThree()
    {
        events[0] = 0;
    }

    int book(int start, int end)
    {
        insert(start);
        insert(end);

        for (auto it = events.find(start); it->first < end; it++)
        {
            it->second++; // Add 1 in all the events(intersection points) from [start, end)
            result = max(result, it->second);
        }

        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */