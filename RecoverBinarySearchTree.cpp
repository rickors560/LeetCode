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
    TreeNode *firstMistake, *secondMistake, *pre;

    void inOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;

        inOrder(node->left);

        if (firstMistake == nullptr && node->val < pre->val)
        {
            // First will store the previous node
            firstMistake = pre;
        }

        if (firstMistake != nullptr && node->val < pre->val)
        {
            // Second will store the current node
            secondMistake = node;
        }

        pre = node;

        inOrder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        pre = new TreeNode(INT_MIN);
        inOrder(root);

        swap(firstMistake->val, secondMistake->val);
    }
};