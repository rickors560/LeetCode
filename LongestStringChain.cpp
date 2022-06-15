#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        auto compare = [](string &a, string &b) -> bool
        {
            return a.length() < b.length();
        };

        sort(words.begin(), words.end(), compare);

        int result = 0;
        unordered_map<string, int> dp;

        for (string w : words)
        {
            for (int i = 0; i < w.length(); i++)
            {
                // Instead of adding 1 character, check by deleting 1 character
                string prev = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(prev) != dp.end() ? dp[prev] + 1 : 1);
            }
            result = max(result, dp[w]);
        }
        return result;
    }
};