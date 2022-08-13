#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.size();
        int m = words.size();

        int wordLength = words[0].size();
        int subStringSize = wordLength * m;

        unordered_map<string, int> wordFreq;

        for (const string word : words)
            wordFreq[word]++;

        vector<int> result;

        for (int i = 0; i <= n - subStringSize; i++)
        {
            unordered_map<string, int> remainingWords(wordFreq);
            int wordsUsed = 0;

            for (int j = i; j < i + subStringSize; j += wordLength)
            {
                string sub = s.substr(j, wordLength);

                if (remainingWords[sub] != 0)
                {
                    remainingWords[sub]--;
                    wordsUsed++;
                }
                else
                    break;
            }

            if (wordsUsed == m)
                result.push_back(i);
        }

        return result;
    }
};