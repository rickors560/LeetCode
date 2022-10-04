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
    bool dfs(TreeNode *node, int targetSum)
    {
        if (!node)
            return false;

        if (!node->left && !node->right && targetSum == node->val)
            return true;

        return dfs(node->left, targetSum - node->val) || dfs(node->right, targetSum - node->val);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum);
    }
};