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
    // Level traversal with linked list (think each level as linked list with next pointers, so we can build nextLevel linked list based on that)
    void setNextPointers2(Node *root)
    {
        Node *currentLevel = root;

        while (currentLevel != NULL)
        {
            Node *nextLevelCurrent = new Node(0);
            Node *nextLevelHead = nextLevelCurrent;

            while (currentLevel)
            {
                if (currentLevel->left != NULL)
                {
                    if (nextLevelCurrent == NULL)
                    {
                        nextLevelCurrent = currentLevel;
                    }
                    nextLevelCurrent->next = currentLevel->left;
                    nextLevelCurrent = currentLevel->left;
                }

                if (currentLevel->right != NULL)
                {
                    if (nextLevelCurrent == NULL)
                        nextLevelCurrent = currentLevel;

                    nextLevelCurrent->next = currentLevel->right;
                    nextLevelCurrent = currentLevel->right;
                }

                currentLevel = currentLevel->next;
            }

            nextLevelCurrent->next = NULL;
            currentLevel = nextLevelHead->next;
        }
    }

    // Using queue for level traversal
    void setNextPointers1(Node *root)
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

            if (currentNode != NULL)
            {

                if (currentNode->left != NULL)
                    q.push(currentNode->left);

                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
            previousNode = currentNode;
        }
    }

public:
    Node *connect(Node *root)
    {
        Node *temp = root;
        setNextPointers2(temp);
        return root;
    }
};