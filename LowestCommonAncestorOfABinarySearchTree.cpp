#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        auto current = root;

        while (current)
        {
            if (current->val > large)
                current = current->left;
            else if (current->val < small)
                current = current->right;
            else
                return current;
        }

        return nullptr;
    }
};