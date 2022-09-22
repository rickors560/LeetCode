#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int lastSpace = -1;

        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                int left = lastSpace + 1;
                int right = i - 1;
                while (left < right)
                {
                    swap(s[left++], s[right--]);
                }

                lastSpace = i;
            }
        }

        return s;
    }
};