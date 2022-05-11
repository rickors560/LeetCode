#include <bits/stdc++.h>
using namespace std;

class Solution
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    int dfs(int n, char lastCharacter)
    {
        if (n == 0)
            return 1;

        int result = 0;

        for (auto vowel : vowels)
        {
            if (vowel >= lastCharacter) // For Lexicographically sorted
            {
                result += dfs(n - 1, vowel);
            }
        }

        return result;
    }

public:
    int countVowelStrings1(int n)
    {
        return dfs(n, '#');
    }

    int countVowelStrings2(int n)
    {
        vector<int> dp(5, 1);

        for (int i = 2; i <= n; i++)
        {
            for (int j = 3; j >= 0; j--) // Skipping last character
            {
                dp[j] += dp[j + 1];
            }
        }

        int ans = 0;
        for (auto x : dp)
            ans += x;

        return ans;
    }
};