#include <bits/stdc++.h>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    queue<int> q;

    void initializeQueue(vector<NestedInteger> nestedList)
    {
        for (auto nested : nestedList)
        {
            if (nested.isInteger())
            {
                q.push(nested.getInteger());
            }
            else
            {
                initializeQueue(nested.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        initializeQueue(nestedList);
    }

    int next()
    {
        int t = q.front();
        q.pop();
        return t;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};
