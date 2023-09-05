#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> newNodes;

        Node *temp = head;
        while (temp != NULL)
        {
            newNodes.insert({temp, new Node(temp->val)});
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL)
        {
            auto newNode = newNodes[temp];
            newNode->next = newNodes[temp->next];
            newNode->random = newNodes[temp->random];
            temp = temp->next;
        }

        return newNodes[head];
    }
};