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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *temp = head;

        int counter = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            counter++;

            // Moving left pointer only till k nodes
            if (counter < k)
            {
                left = left->next;
            }

            // Moving right pointer after k nodes
            if (counter > k)
            {
                right = right->next;
            }
        }

        // Swap left & right values
        auto tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        return head;
    }
};