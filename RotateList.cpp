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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp)
        {
            temp = temp->next;
            length++;
        }

        if (length < 2 || k == 0 || k % length == 0)
            return head;

        int rotations = k % length;
        int t = length - rotations;

        temp = head;
        int i = 0;
        while (i < t - 1)
        {
            temp = temp->next;

            i++;
        }

        // Cut the list
        ListNode *fistpart = temp->next;
        ListNode *ans = fistpart;
        temp->next = NULL;

        i = 0;
        while (i < rotations - 1)
        {
            fistpart = fistpart->next;
            i++;
        }
        // Move the nodes [ nodes that were to be rotated ] to the starting of list
        fistpart->next = head;
        return ans;
    }
};