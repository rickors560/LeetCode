#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; }); // Sort courses on the base of their deadlines

        priority_queue<int> pq; // Max-Heap

        int time = 0;
        for (auto course : courses)
        {
            time += course[0];
            pq.push(course[0]);

            if (time > course[1]) // if time exceeds the deadline, drop the previous course which costs the most time. (That must be the best choice!)
            {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};