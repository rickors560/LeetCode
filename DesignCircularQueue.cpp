#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
    class ListNode
    {
    public:
        int val;
        ListNode *next;
        ListNode(int x)
        {
            val = x;
            next = NULL;
        }
    };

    int maxSize, currentSize;
    ListNode *front, *rear;

public:
    MyCircularQueue(int k)
    {
        maxSize = k;
        currentSize = 0;
        front = NULL;
        rear = NULL;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        ListNode *newNode = new ListNode(value);

        if (!front && !rear)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
        }
        newNode->next = front;
        rear = newNode;
        currentSize++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
            delete rear->next;
            rear->next = front;
        }
        currentSize--;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : front->val;
    }

    int Rear()
    {
        return isEmpty() ? -1 : rear->val;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == maxSize;
    }
};