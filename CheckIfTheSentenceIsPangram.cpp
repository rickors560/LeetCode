#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        if (sentence.size() < 26)
            return false;

        bool seen[26] = {0};

        for (char c : sentence)
            seen[c - 'a'] = true;

        for (int i = 0; i < 26; i++)
            if (!seen[i])
                return false;

        return true;
    }
};