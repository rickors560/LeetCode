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
    bool containsOne(TreeNode *node)
    {
        if (!node)
            return false;

        bool left = containsOne(node->left);
        bool right = containsOne(node->right);

        if (!left)
            node->left = NULL;
        if (!right)
            node->right = NULL;

        return node->val == 1 || left || right;
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        return containsOne(root) ? root : NULL;
    }
};