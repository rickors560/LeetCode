#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;

        if (!root)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            while (size-- > 0)
            {
                auto node = q.front();
                q.pop();
                if (!node)
                    continue;

                temp.push_back(node->val);

                for (auto child : node->children)
                {
                    q.push(child);
                }
            }
            result.push_back(temp);
        }

        return result;
    }
};