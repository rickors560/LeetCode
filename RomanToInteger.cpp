#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int romanToInt1(string s)
    {
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int result = 0;
        int prev = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            int current = table[s[i]];

            if (prev < current)
            {
                result += current - 2 * prev;
            }
            else
            {
                result += current;
            }
            prev = current;
        }

        return result;
    }

    int romanToInt2(string s)
    {
        unordered_map<string, int> table = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}};

        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (table.find(s.substr(i, 2)) != table.end())
            {
                result += table[s.substr(i++, 2)];
            }
            else
            {
                result += table[s.substr(i, 1)];
            }
        }

        return result;
    }
};