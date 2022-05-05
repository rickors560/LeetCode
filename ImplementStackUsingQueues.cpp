#include <bits/stdc++.h>

using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++)
        {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }

    int pop()
    {
        int t = q.front();
        q.pop();
        return t;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};