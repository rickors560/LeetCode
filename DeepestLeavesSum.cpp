#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int maxLevel = 0;
    int sum = 0;

    void dfs(TreeNode *root, int level)
    {
        if (root == NULL)
            return;

        if (level > maxLevel)
        {
            sum = 0;
            maxLevel = level;
        }

        if (level == maxLevel)
            sum += root->val;

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    int levelTraversal(TreeNode *root)
    {
        int result = 0;
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            result = 0;
            int i = q.size() - 1; // To only traverse that level nodes.

            while (i >= 0)
            {
                TreeNode *node = q.front();
                q.pop();

                result += node->val;

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);

                i--;
            }
        }

        return result;
    }

public:
    int
    deepestLeavesSum(TreeNode *root)
    {
        // dfs(root, 0);
        // return sum;
        return levelTraversal(root);
    }
};