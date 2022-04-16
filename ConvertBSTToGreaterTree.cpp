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
    int lastGreaterValue = 0;

public:
    // "Reverse In-order Traversal"
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        // As its BST, first we'll go to most greater node that (i.e., right most leaf node )
        convertBST(root->right);

        // Update the last most greater value
        root->val += lastGreaterValue;
        lastGreaterValue = root->val;

        // Move to left subtree
        convertBST(root->left);

        return root;
    }
};