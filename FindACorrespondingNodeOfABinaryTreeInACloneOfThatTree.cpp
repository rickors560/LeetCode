#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    TreeNode *dfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == NULL)
            return NULL;

        if (original == target)
            return cloned;

        auto left = dfs(original->left, cloned->left, target);
        auto right = dfs(original->right, cloned->right, target);

        return left != NULL ? left : right;
    }

    TreeNode *bfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        queue<TreeNode *> qOriginal;
        queue<TreeNode *> qCloned;

        qOriginal.push(original);
        qCloned.push(cloned);

        while (!qOriginal.empty())
        {
            auto originalNode = qOriginal.front();
            qOriginal.pop();
            auto clonedNode = qCloned.front();
            qCloned.pop();

            if (originalNode == target)
                return clonedNode;

            if (originalNode->left != NULL)
            {
                qOriginal.push(originalNode->left);
                qCloned.push(clonedNode->left);
            }

            if (originalNode->right != NULL)
            {
                qOriginal.push(originalNode->right);
                qCloned.push(clonedNode->right);
            }
        }

        return NULL;
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // return dfs(original, cloned, target);
        return bfs(original, cloned, target);
    }
};