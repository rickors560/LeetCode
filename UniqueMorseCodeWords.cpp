#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> result;

        for (auto word : words)
        {
            string code = "";
            for (int i = 0; i < word.size(); i++)
            {
                code += morseCode[word[i] - 'a'];
            }
            result.insert(code);
        }

        return result.size();
    }
};