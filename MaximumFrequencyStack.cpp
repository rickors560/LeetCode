#include <bits/stdc++.h>

using namespace std;

class FreqStack
{
private:
    unordered_map<int, int> frequency;
    int currentMaxFrequency = 0;
    unordered_map<int, stack<int>> groups;

public:
    FreqStack()
    {
    }

    void push(int val)
    {
        currentMaxFrequency = max(currentMaxFrequency, ++frequency[val]);
        groups[frequency[val]].push(val);
    }

    int pop()
    {
        int t = groups[currentMaxFrequency].top();
        groups[currentMaxFrequency].pop();

        if (!groups[frequency[t]--].size() > 0)
            currentMaxFrequency--;

        return t;
    }
};