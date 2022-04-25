#include <bits/stdc++.h>

using namespace std;

// Only Interface dont change
class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    int next();

    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
    int peekedElement = NULL;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        if (peekedElement == NULL)
        {
            peekedElement = Iterator::next();
        }
        return peekedElement;
    }

    int next()
    {
        if (peekedElement == NULL)
            return Iterator::next();

        int temp = peekedElement;
        peekedElement = NULL;
        return temp;
    }

    bool hasNext() const
    {
        return peekedElement != NULL || Iterator::hasNext();
    }
};