#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> pq;

        int sum = 0;

        for (int i : target)
        {
            sum += i;
            pq.push(i);
        }

        while (true)
        {
            int current = pq.top();
            pq.pop();
            sum -= current;

            if (current == 1 || sum == 1)
                return true;

            if (current < sum || sum == 0)
                return false;

            int newCurrent = current % sum;

            if (newCurrent == 0)
                return false;

            sum += newCurrent;
            pq.push(newCurrent);
        }

        return true;
    }
};
