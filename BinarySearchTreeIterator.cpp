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

// With Space complexity of O(n)   [n = number of elements]
class BSTIterator1
{
    stack<int> st;

    void revInOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;

        revInOrder(node->right);

        st.push(node->val);

        revInOrder(node->left);
    }

public:
    BSTIterator1(TreeNode *root)
    {
        revInOrder(root);
    }

    int next()
    {
        int next = st.top();
        st.pop();
        return next;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

// With Space complexity of O(h)  [h = height of tree]
class BSTIterator
{
    stack<TreeNode *> st;

    void pushInStack(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushInStack(root);
    }

    int next()
    {
        auto top = st.top();
        st.pop();

        pushInStack(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};