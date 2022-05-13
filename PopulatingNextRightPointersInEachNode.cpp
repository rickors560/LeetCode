#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
    // Level traversal with queue
    void setNextPointers(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        queue<Node *> q;

        q.push(root);
        q.push(NULL); // Level terminator;

        Node *previousNode = NULL;
        while (!q.empty())
        {
            Node *currentNode = q.front();
            q.pop();

            if (previousNode != NULL)
                previousNode->next = currentNode;

            if (currentNode == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                if (currentNode->left != NULL)
                    q.push(currentNode->left);

                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }

            previousNode = currentNode;
        }
    }

public:
    Node *connect(Node *root)
    {
        Node *temp = root;
        setNextPointers(root);
        return root;
    }
};