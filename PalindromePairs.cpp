#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPalindrome(string &s)
    {
        int l = 0;
        int r = s.size() - 1;
        return isPalindrome(s, l, r);
    }

    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
            if (s[l++] != s[r--])
                return false;

        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> result;
        unordered_map<string, int> mp;
        unordered_set<int> lengths; // For only checking valid cut to look

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            mp[word] = i;
            lengths.insert(word.size());
        }

        if (mp.count("") != 0)
        {
            int blankStrIndex = mp[""];
            for (int i = 0; i < n; i++)
            {
                if (i != blankStrIndex && isPalindrome(words[i]))
                {
                    result.push_back({blankStrIndex, i});
                    result.push_back({i, blankStrIndex});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            string reversedStr = words[i];
            reverse(reversedStr.begin(), reversedStr.end());
            if (mp.count(reversedStr) != 0 && mp[reversedStr] != i)
            {
                result.push_back({i, mp[reversedStr]});
            }
        }

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            string reversed = word;
            reverse(reversed.begin(), reversed.end());

            if (word == "")
                continue;

            for (int cut : lengths) // For checking valid cut to look and not look at each cut (index) in word
            {
                if (cut == 0 || cut >= word.size())
                    continue;

                if (isPalindrome(reversed, 0, reversed.size() - cut - 1))
                {
                    string right = reversed.substr(reversed.size() - cut);
                    if (mp.count(right) != 0 && mp[right] != i)
                    {
                        result.push_back({i, mp[right]});
                    }
                }

                if (isPalindrome(reversed, cut, reversed.size() - 1))
                {
                    string left = reversed.substr(0, cut);
                    if (mp.count(left) != 0 && mp[left] != i)
                    {
                        result.push_back({mp[left], i});
                    }
                }
            }
        }

        return result;
    }
};