#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.size();

        if (n < k)
            return s;

        stack<pair<char, int>> frequency;

        for (char c : s)
        {
            if (frequency.empty() || frequency.top().first != c)
            {
                frequency.push({c, 1});
            }
            else
            {
                frequency.top().second += 1;
            }

            if (frequency.top().second == k)
                frequency.pop();
        }

        string ans = "";

        while (!frequency.empty())
        {
            auto current = frequency.top();
            frequency.pop();

            while (current.second > 0)
            {
                ans += current.first;
                current.second--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};