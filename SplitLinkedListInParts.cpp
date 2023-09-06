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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> result(k);
        int n = 0;

        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }

        int l = n / k;
        int r = n % k;

        ListNode *node = head;
        ListNode *prev = NULL;
        int i = 0;

        while (i < k && node != NULL)
        {
            result[i] = node;

            for (int j = 0; j < l + (r > 0); j++)
            {
                prev = node;
                node = node->next;
            }

            prev->next = NULL;
            i++;
            r--;
        }

        return result;
    }
};