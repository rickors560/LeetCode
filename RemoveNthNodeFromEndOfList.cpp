#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == NULL)
        {
            return NULL;
        }

        ListNode *s = head;
        ListNode *f = head;

        for (int i = 0; i < n; i++)
        {
            f = f->next;
        }

        if(f == NULL)
            return head->next;

        while (f->next != NULL)
        {
            s = s->next;
            f = f->next;
        }

        s->next = s->next->next;
        return s;
    }
};