#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
    vector<bool> lookUp;

public:
    MyHashSet() : lookUp(1000000 + 1, false)
    {
    }

    void add(int key)
    {
        lookUp[key] = true;
    }

    void remove(int key)
    {
        lookUp[key] = false;
    }

    bool contains(int key)
    {
        return lookUp[key];
    }
};