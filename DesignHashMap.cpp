#include <bits/stdc++.h>

using namespace std;

class MyHashMap
{
    vector<int> lookUp;

public:
    MyHashMap() : lookUp(1000001, -1)
    {
    }

    void put(int key, int value)
    {
        lookUp[key] = value;
    }

    int get(int key)
    {
        return lookUp[key];
    }

    void remove(int key)
    {
        lookUp[key] = -1;
    }
};