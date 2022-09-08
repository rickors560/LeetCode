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
    void dfs(TreeNode *node, vector<int> &result)
    {
        if (!node)
            return;
        dfs(node->left, result);
        result.push_back(node->val);
        dfs(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};