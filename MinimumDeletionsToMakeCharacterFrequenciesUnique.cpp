#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using hash set
    int minDeletions(string s)
    {
        vector<int> frequency(26, 0);

        for (auto c : s)
            frequency[c - 'a']++;

        int result = 0;
        unordered_set<int> used;

        for (int i = 0; i < 26; i++)
        {
            while (frequency[i] > 0 && used.find(frequency[i]) != used.end())
            {
                result++;
                frequency[i]--;
            }
            used.insert(frequency[i]);
        }

        return result;
    }

    // Using Max Heap (Priority Queue)
    int minDeletions1(string s)
    {
        vector<int> frequency(26, 0);

        for (auto c : s)
            frequency[c - 'a']++;

        priority_queue<int> pq; // Max heap

        for (int i = 0; i < 26; i++)
        {
            if (frequency[i])
                pq.push(frequency[i]);
        }

        int result = 0;

        while (pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();

            if (top == pq.top())
            {
                if (top - 1 > 0)
                    pq.push(top - 1);

                result++;
            }
        }

        return result;
    }
};