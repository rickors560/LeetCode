#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            // For odd length palindromes
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                result++;
                left--;
                right++;
            }

            // For even length palindromes
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                result++;
                left--;
                right++;
            }
        }

        return result;
    }
};