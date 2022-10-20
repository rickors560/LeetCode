#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        auto nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        nextNode->next = NULL;
        delete (nextNode);
    }
};