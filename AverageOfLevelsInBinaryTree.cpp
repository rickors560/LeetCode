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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0, count = 0;
            while (size > 0) // Level Traversal
            {
                auto node = q.front();
                q.pop();

                sum += node->val;
                count++;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                size--;
            }
            result.push_back((sum * 1.0) / count);
        }

        return result;
    }
};