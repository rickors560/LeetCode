#include <bits/stdc++.h>

using namespace std;

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> queue;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (auto num : nums)
        {
            queue.push(num);
        }

        while (queue.size() > k)
        {
            queue.pop();
        }
    }

    int add(int val)
    {
        queue.push(val);

        if (queue.size() > k)
        {
            queue.pop();
        }
        return queue.top();
    }
};
