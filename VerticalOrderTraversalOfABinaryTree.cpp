#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;   // Can use min heap (priority queue) => map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>
        queue<pair<TreeNode *, pair<int, int>>> q; // Node, x, y
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> result;

        for (auto node : nodes)
        {
            vector<int> col;
            for (auto x : node.second)
            {
                // Insert at the end
                col.insert(col.end(), x.second.begin(), x.second.end());
            }

            result.push_back(col);
        }

        return result;
    }
};