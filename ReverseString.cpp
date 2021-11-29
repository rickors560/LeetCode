#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            char t = s[r];
            s[r] = s[l];
            s[l] = t;

            l++;
            r--;
        }
    }
};