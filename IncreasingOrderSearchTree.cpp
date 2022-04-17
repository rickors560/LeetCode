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
    TreeNode *currentNode;
    void inOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;

        inOrder(node->left);

        node->left = nullptr;
        currentNode->right = node;
        currentNode = node;

        inOrder(node->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *answer = new TreeNode(0);

        currentNode = answer;

        inOrder(root);

        return answer->right;
    }
};