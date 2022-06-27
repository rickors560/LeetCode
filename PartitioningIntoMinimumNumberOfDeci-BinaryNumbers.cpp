#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        // * for dereferencing the forward iterator
        return *max_element(n.begin(), n.end()) - '0';
    }
};