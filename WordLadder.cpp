#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> todo;

        todo.push(beginWord);

        int result = 1;
        while (!todo.empty())
        {
            int n = todo.size();

            // Processing Adjacent Neighbour's of one level at a time.
            for (int i = 0; i < n; i++)
            {
                string word = todo.front();
                todo.pop();

                if (word == endWord)
                    return result;

                wordSet.erase(word);

                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];

                    for (int ch = 0; ch < 26; ch++)
                    {
                        word[j] = 'a' + ch;

                        if (wordSet.find(word) != wordSet.end())
                            todo.push(word);
                    }

                    word[j] = c;
                }
            }

            result++;
        }

        return 0;
    }
};