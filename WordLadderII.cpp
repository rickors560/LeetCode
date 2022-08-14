#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;
    unordered_map<string, unordered_set<string>> adjacentWords;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return result;

        // Use BFS to generate adjacent nodes of words.
        bfs(beginWord, endWord, wordSet);

        // DFS on adjacent nodes to get result.
        // Start from endWord -> beginWord, otherwise in case of beginWord -> endWord the paths we have to check is more and it will time consuming
        vector<string> path;
        dfs(endWord, beginWord, adjacentWords, path);

        return result;
    }

    void bfs(string &beginWord, string &endWord, unordered_set<string> &wordSet)
    {
        unordered_map<string, int> graphLevels;

        queue<string> todo;

        todo.push(beginWord);
        graphLevels[beginWord] = 0;

        int level = 0;
        while (!todo.empty())
        {
            int n = todo.size();
            while (n > 0)
            {
                string current = todo.front();
                todo.pop();

                string word = current;
                for (int i = 0; i < word.size(); i++)
                {
                    char c = word[i];

                    for (int j = 0; j < 26; j++)
                    {
                        word[i] = 'a' + j;

                        if (current != word && wordSet.find(word) != wordSet.end()) // Its present within our dictionary
                        {
                            if (graphLevels.count(word) == 0) // Its never been visited
                            {
                                graphLevels[word] = level;

                                // Building graph in reverse order i.e., [u, v] = u <- v edge as we are doing dfs from endWord to beginWord for optimization.
                                adjacentWords[word].insert(current);

                                if (word != endWord)
                                    todo.push(word);
                            }

                            else if (graphLevels[word] == graphLevels[current] + 1) // Its been visited and its 1 level adjacent to current word.
                                adjacentWords[word].insert(current);
                        }
                    }

                    word[i] = c;
                }

                n--;
            }
            level++;
        }
    }

    void dfs(string &curentWord, string &endWord, unordered_map<string, unordered_set<string>> &adjacentWords, vector<string> &path)
    {
        path.push_back(curentWord);
        if (curentWord == endWord)
        {
            vector<string> temp(path.begin(), path.end());
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            path.pop_back();
            return;
        }

        for (auto adj : adjacentWords[curentWord])
            dfs(adj, endWord, adjacentWords, path);

        path.pop_back();
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------------
// Another approach but got TLE
// For building the whole path from last node
class Node
{
public:
    string word;
    Node *parent;

    Node(string word) : parent(NULL)
    {
        this->word = word;
    };

    Node(string word, Node *parent)
    {
        this->word = word;
        this->parent = parent;
    };
};

class Solution
{
    unordered_set<string> findNeighbors(unordered_set<string> &wordSet, string word)
    {
        unordered_set<string> result;
        wordSet.erase(word);

        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];

            for (int j = 0; j < 26; j++)
            {
                word[i] = 'a' + j;

                if (wordSet.find(word) != wordSet.end())
                    result.insert(word);
            }

            word[i] = c;
        }

        return result;
    }

    void addToResult(vector<vector<string>> &result, Node *p)
    {
        vector<string> path;
        while (p)
        {
            path.push_back(p->word);
            p = p->parent;
        }

        reverse(path.begin(), path.end());
        result.push_back(path);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (wordSet.find(endWord) == wordSet.end())
            return result;

        queue<Node *> todo;
        todo.push(new Node(beginWord));

        while (!todo.empty())
        {
            int n = todo.size();

            while (--n >= 0)
            {
                Node *current = todo.front();
                todo.pop();

                for (string neighbourWord : findNeighbors(wordSet, current->word))
                {
                    Node *neighbour = new Node(neighbourWord, current);
                    if (neighbourWord == endWord)
                    {
                        addToResult(result, neighbour);
                        break;
                    }
                    todo.push(neighbour);
                }
            }

            // As we need shortest path, asap data get filled we need to break as need not to go further down level
            if (result.size() > 0)
                break;
        }

        return result;
    }
};