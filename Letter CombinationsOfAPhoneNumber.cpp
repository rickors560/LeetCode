#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<string> lookUp{
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;

        if (digits.size() > 0)
        {
            string s = "";
            backTrack(0, digits, s, result);
        }

        return result;
    }

    void backTrack(int d, string &digits, string &currentString, vector<string> &result)
    {
        if (currentString.size() == digits.size())
        {
            result.push_back(currentString);
            return;
        }

        string alphabets = lookUp[digits[d] - '2'];

        for (char c : alphabets)
        {
            string s = currentString + c;
            backTrack(d + 1, digits, s, result);
        }
    }
};