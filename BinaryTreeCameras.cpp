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
    enum
    {
        NO_CAMERA,
        HAS_CAMERA,
        NOT_NEEDED
    };

    int result = 0;

    int dfs(TreeNode *root)
    {
        if (!root)
            return NOT_NEEDED;

        if (!root->left && !root->right)
            return NO_CAMERA;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == NO_CAMERA || right == NO_CAMERA)
        {
            result++;
            return HAS_CAMERA;
        }

        if (left == HAS_CAMERA || right == HAS_CAMERA)
            return NOT_NEEDED;

        return NO_CAMERA;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        if (dfs(root) == NO_CAMERA)
            result++;
        return result;
    }
};