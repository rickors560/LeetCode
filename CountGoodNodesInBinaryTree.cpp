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
    int count = 0;

    void dfs(TreeNode *node, int currentMax)
    {
        if (!node)
            return;

        if (node->val >= currentMax)
        {
            count++;
            currentMax = node->val;
        }

        dfs(node->left, currentMax);
        dfs(node->right, currentMax);
    }

public:
    int goodNodes(TreeNode *root)
    {
        dfs(root, root->val);
        return count;
    }
};