#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        auto words = split(s, ' ');
        string result = "";
        for (auto x : words)
        {
            result += reverse(x) + " ";
        }
        int n = result.size();
        result = result.substr(0, n - 1);
        return result;
    }

    vector<string> split(string s, char delimeter)
    {
        vector<string> res;
        string word = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == delimeter)
            {
                res.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }
        res.push_back(word);

        return res;
    }

    string reverse(string word)
    {
        int n = word.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            char t = word[r];
            word[r] = word[l];
            word[l] = t;

            l++;
            r--;
        }
        return word;
    }
};