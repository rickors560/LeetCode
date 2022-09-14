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

// <========================================>Using Recursion with bit manipulation for managing frequencies<========================================>

class Solution
{

    void dfs(TreeNode *node, int &paths, int frequency)
    {
        if (!node)
            return;

        // Bit position will denote if the frequency of the position number is odd then bit will 1 else is even bit will 0
        frequency = frequency ^ (1 << node->val); // Using bit manipulation and xor to maintain the frequency (If odd frequency position bit is to 1)

        if (!node->left && !node->right) // leaf node
            // Basically checking if frequency is power of 2 or not (If it power of 2 then it will at most one bit set to 1 [which is frequency in our case])
            paths += (frequency & (frequency - 1)) == 0; // Check if at most one bit is set to 1 (Odd frequency) by setting the right most 1 bit to 0.

        dfs(node->left, paths, frequency);
        dfs(node->right, paths, frequency);
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int paths = 0;
        vector<int> frequency(10);
        dfs(root, paths, 0);
        return paths;
    }
};

// <========================================>Using Recursion<========================================>

class Solution1
{
    void dfs(TreeNode *node, int &paths, vector<int> &frequency)
    {
        if (!node)
            return;

        frequency[node->val]++;

        if (!node->left && !node->right) // leaf node
            paths += isPseudoPalindromicPath(frequency);

        dfs(node->left, paths, frequency);
        dfs(node->right, paths, frequency);

        frequency[node->val]--;
    }

    bool isPseudoPalindromicPath(vector<int> &frequency)
    {
        int oddCount = 0;
        for (int i = 0; i < 10; i++)
            if (frequency[i] % 2 != 0)
                oddCount++;

        return oddCount <= 1;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int paths = 0;
        vector<int> frequency(10);
        dfs(root, paths, frequency);
        return paths;
    }
};