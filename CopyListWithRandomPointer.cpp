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
    // More efficient way
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *temp = head;

        // Insert a copy node to make [ A -> B -> C ] to [ A -> A` -> B -> B` -> C -> C` ]
        while (temp != NULL)
        {
            Node *t = temp->next;

            temp->next = new Node(temp->val);

            temp->next->next = t;

            temp = t;
        }

        temp = head;

        // Copy the random pointer
        while (temp != NULL)
        {
            temp->next->random = (temp->random != NULL) ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        Node *orginalList = head;
        Node *newList = head->next;
        temp = newList;

        // Restoring the original list and new copy list
        while (orginalList != NULL)
        {
            orginalList->next = orginalList->next->next;
            temp->next = (temp->next != NULL) ? temp->next->next : NULL;

            orginalList = orginalList->next;
            temp = temp->next;
        }

        return newList;
    }

    // Using map as a cache for random pointer ( Has more space complexity )
    Node *copyRandomListUsingMap(Node *head)
    {
        map<Node *, Node *> cache;

        Node *temp = head;

        while (temp != NULL)
        {
            cache.insert({temp, new Node(temp->val)});
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            cache[temp]->next = cache[temp->next];
            cache[temp]->random = cache[temp->random];

            temp = temp->next;
        }

        return cache[head];
    }
};