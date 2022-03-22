#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string ans(n, 'a');
        while (k > 0 && n > 0)
        {
            int letter = min(26, k - n + 1);
            ans[--n] += letter - 1;
            k -= letter;
        }
        return ans;
    }
};