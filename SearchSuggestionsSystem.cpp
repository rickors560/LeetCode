#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;
};

class Solution
{
    TrieNode *root;

    void insertInTrieNode(string &word)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            if (!current->children[c - 'a'])
                current->children[c - 'a'] = new TrieNode();

            current = current->children[c - 'a'];
        }
        current->isEndOfWord = true;
    }

    vector<string> searchTrieNodeWithPrefix(string prefix)
    {
        TrieNode *current = root;
        vector<string> result;

        // Moving current node to end of prefix.
        for (auto c : prefix)
        {
            if (!current->children[c - 'a'])
                return result;

            current = current->children[c - 'a'];
        }

        // DFS on current node i.e., all words starting from prefix.
        dfs(current, prefix, result);

        return result;
    }

    void dfs(TrieNode *current, string &prefix, vector<string> &result)
    {
        if (result.size() == 3)
            return;

        if (current->isEndOfWord)
            result.push_back(prefix);

        // Checking all possible paths from that node.
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (!current->children[c - 'a'])
                continue;

            prefix += c;
            dfs(current->children[c - 'a'], prefix, result);
            prefix.pop_back();
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        root = new TrieNode();

        for (auto word : products)
            insertInTrieNode(word);

        vector<vector<string>> result;

        string prefix;

        for (auto c : searchWord)
        {
            prefix += c;
            result.push_back(searchTrieNodeWithPrefix(prefix));
        }

        return result;
    }
};