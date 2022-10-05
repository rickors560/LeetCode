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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            auto newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }

        queue<TreeNode *> q;
        q.push(root);
        int currentDepth = 1;

        while (currentDepth < depth - 1)
        {
            int n = q.size();
            while (n--)
            {
                auto node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            currentDepth++;
        }

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            auto l = node->left;
            auto r = node->right;
            node->left = new TreeNode(val, l, NULL);
            node->right = new TreeNode(val, NULL, r);
        }

        return root;
    }
};