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
    void dfs(TreeNode *node, int targetSum, vector<vector<int>> &result, vector<int> &currentPath)
    {
        if (!node)
            return;

        currentPath.push_back(node->val);

        if (!node->left && !node->right && node->val == targetSum)
            result.push_back(currentPath);

        dfs(node->left, targetSum - node->val, result, currentPath);
        dfs(node->right, targetSum - node->val, result, currentPath);
        currentPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, result, currentPath);
        return result;
    }
};