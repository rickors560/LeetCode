#include <bits/stdc++.h>

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *sequential = new ListNode(0, head);

        ListNode *predecessor = sequential;

        while (head != NULL && head->next != NULL)
        {
            if (head->next != NULL && head->val != head->next->val)
            {
                predecessor = predecessor->next;
            }
            else
            {
                while (head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }
                predecessor->next = head->next;
            }
            head = head->next;
        }

        return sequential->next;
    }
};