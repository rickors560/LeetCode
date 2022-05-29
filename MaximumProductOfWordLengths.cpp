#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Bit Manipulation
    int maxProduct1(vector<string> words)
    {
        int n = words.size();
        vector<int> bitMasks;

        for (auto word : words)
        {
            int mask = 0;
            for (char c : word)
            {
                mask |= (1 << (c - 'a')); // Creating a bit mask for character
            }
            bitMasks.push_back(mask);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((bitMasks[i] & bitMasks[j]) == 0)
                {
                    int t = words[i].size() * words[j].size();
                    result = max(result, t);
                }
            }
        }
        return result;
    }

    // Brute force
    int maxProduct2(vector<string> &words)
    {
        int result = 0;

        for (int i = 0; i < words.size(); i++)
        {
            string a = words[i];

            int count[26] = {};
            for (char c : a)
                count[c - 'a']++;

            for (int j = i + 1; j < words.size(); j++)
            {
                string b = words[j];

                bool hasCommon = false;

                for (char c : b)
                {
                    if (count[c - 'a'] != 0)
                    {
                        hasCommon = true;
                        break;
                    }
                }

                if (hasCommon)
                    continue;

                int t = a.size() * b.size();
                result = max(result, t);
            }
        }
        return result;
    }
};