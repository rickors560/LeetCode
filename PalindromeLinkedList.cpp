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
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *currentNode = head;
        while (currentNode)
        {
            auto next = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = next;
        }

        return prev; // New head
    }

public:
    bool isPalindrome(ListNode *head)
    {
        auto slow = head;
        auto fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto end = reverseLinkedList(slow);
        auto front = head;

        while (front && end)
        {
            if (front->val != end->val)
                return false;

            front = front->next;
            end = end->next;
        }

        return true;
    }
};