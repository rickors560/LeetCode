#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    int count;
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        map<TrieNode *, int> nodes;

        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *currentNode = root;

            for (int j = words[i].size() - 1; j >= 0; j--)
            {
                int c = words[i][j] - 'a';

                if (!currentNode->children[c])
                {
                    currentNode->children[c] = new TrieNode();
                    currentNode->count++; // for all substrings count will be non zero at last Trie Node
                }
                currentNode = currentNode->children[c];
            }

            nodes[currentNode] = i;
        }

        int result = 0;

        for (auto entry : nodes)
        {
            if (!entry.first->count)
            {
                result += words[entry.second].size() + 1;
            }
        }

        return result;
    }
};