#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> sCount;
        unordered_map<char, int> tCount;

        for (char c : t)
            tCount[c]++;

        string result;
        int currentSize = INT_MAX;

        int lettersNeeded = 0;

        int left = 0;
        int right = 0;

        while (left <= right && right < s.size())
        {
            auto currentChar = s[right];

            if (tCount.count(currentChar) != 0)
            {
                sCount[currentChar]++;
                if (tCount[currentChar] >= sCount[currentChar])
                    lettersNeeded++;
            }

            if (lettersNeeded >= t.size())
            {
                // Resizing window to optimal t characters frequency
                // Whether s[left] is not t or its frequency more than required
                while (tCount.count(s[left]) == 0 || sCount[s[left]] > tCount[s[left]])
                {
                    sCount[s[left]]--;
                    left++;
                }

                int currentWindowSize = right - left + 1;
                if (currentWindowSize < currentSize)
                {
                    result = s.substr(left, currentWindowSize);
                    currentSize = currentWindowSize;
                }
            }

            right++;
        }

        return result;
    }
};