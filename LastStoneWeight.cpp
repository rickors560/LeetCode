#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> queue(stones.begin(), stones.end());

        while (!queue.empty())
        {
            if (queue.size() == 1)
            {
                return queue.top();
            }

            int a = queue.top();
            queue.pop();
            int b = queue.top();
            queue.pop();

            if (a - b == 0)
            {
                continue;
            }
            else
            {
                queue.push(a - b);
            }
        }

        return 0;
    }
};