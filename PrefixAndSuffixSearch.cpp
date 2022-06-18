#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    int weight;

    TrieNode()
    {
        children = vector<TrieNode *>(27, NULL);
        weight = 0;
    }

    // To prevent memory leak
    ~TrieNode()
    {
        for (int i = 0; i <= 26; i++)
        {
            if (children[i])
            {
                delete children[i];
            }
        }
    }
};

// Using trie node
class WordFilter
{
    TrieNode *root;

public:
    WordFilter(vector<string> &words)
    {
        TrieNode *node = new TrieNode();
        root = node;

        int index = 0;
        for (auto word : words)
        {

            // add "apple{apple", "pple{apple", "ple{apple", "le{apple", "e{apple", "{apple" into the Trie Tree
            string searchWord = word;

            for (int i = word.size(); i >= 0; i--)
            {
                // '{' using as a seperator as in ASCII code its just after 'z
                searchWord = (i == word.size() ? '{' : word[i]) + searchWord;
                node = root;

                for (char c : searchWord)
                {

                    if (!node->children[c - 'a'])
                        node->children[c - 'a'] = new TrieNode();

                    node = node->children[c - 'a'];
                    node->weight = index;
                }
            }

            index++;
        }
    }

    int f(string prefix, string suffix)
    {
        TrieNode *node = root;
        string search = suffix + "{" + prefix;
        for (char c : search)
        {
            if (!node->children[c - 'a'])
                return -1;
            node = node->children[c - 'a'];
        }

        return node->weight;
    }
};

// Using map
class WordFilter1
{
    unordered_map<string, int> mp;

public:
    WordFilter1(vector<string> &words)
    {
        int index = 0;

        for (auto word : words)
        {
            for (int i = 0; i <= word.size(); i++)
            {
                for (int j = 0; j <= word.size(); j++)
                {
                    mp[word.substr(0, i) + "#" + word.substr(j)] = index;
                }
            }
            index++;
        }
    }

    int f(string prefix, string suffix)
    {
        string key = prefix + "#" + suffix;
        return mp.find(key) != mp.end() ? mp[key] : -1;
    }
};