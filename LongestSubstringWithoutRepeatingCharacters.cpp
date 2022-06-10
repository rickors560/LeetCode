#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        unordered_map<char, int> m;
        int result = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
                start = max(start, m[s[i]] + 1);

            m[s[i]] = i;
            result = max(result, i - start + 1);
        }

        return result;
    }
};