#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> arabic = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        for (int i = 0; i < arabic.size(); i++)
        {
            while (num / arabic[i])
            {
                result += romans[i];
                num -= arabic[i];
            }
        }

        return result;
    }
};