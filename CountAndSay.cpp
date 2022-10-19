#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string countAndSayHelper(string s)
    {
        string result = "";
        char currentCharacter = s[0];
        int count = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == currentCharacter)
                count++;
            else
            {
                result += to_string(count) + currentCharacter;
                currentCharacter = s[i];
                count = 1;
            }
        }
        result += to_string(count) + currentCharacter;
        return result;
    }

public:
    string countAndSay(int n)
    {
        string result = "1";

        for (int i = 1; i < n; i++)
            result = countAndSayHelper(result);

        return result;
    }
};