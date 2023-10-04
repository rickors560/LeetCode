#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, val;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        val = v;
        next = NULL;
    }
};

class MyHashMap
{
private:
    vector<Node *> buckets;
    static const int numOfBuckets = 1000;

    int getHash(int key)
    {
        return key % numOfBuckets;
    }

public:
    MyHashMap()
    {
        buckets = vector<Node *>(numOfBuckets, NULL);
    }

    void put(int key, int value)
    {
        int hash = getHash(key);

        if (buckets[hash] == NULL)
        {
            buckets[hash] = new Node(key, value);
        }
        else
        {
            Node *curr = buckets[hash];
            while (curr)
            {
                if (curr->key == key)
                {
                    curr->val = value;
                    return;
                }
                if (!curr->next)
                {
                    break;
                }
                curr = curr->next;
            }
            curr->next = new Node(key, value);
        }
    }

    int get(int key)
    {
        int hash = getHash(key);
        Node *curr = buckets[hash];

        while (curr)
        {
            if (curr->key == key)
            {
                return curr->val;
            }

            curr = curr->next;
        }

        return -1;
    }

    void remove(int key)
    {
        int hash = getHash(key);
        Node *curr = buckets[hash];
        Node *prev = NULL;

        while (curr)
        {
            if (curr->key == key)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    buckets[hash] = curr->next;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */