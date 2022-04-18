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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;

        while (1)
        {
            // Push all left nodes
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            // Move root to last pushed node
            root = st.top();
            st.pop();

            k--;

            // Check if k == 0 then we have the result
            if (k == 0)
                return root->val;

            // If not then move root to right node
            root = root->right;
        }
    }
};