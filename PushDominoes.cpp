#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
                q.push(i);
        }

        // Processing second by second transitions
        while (!q.empty())
        {
            int index = q.front();
            q.pop();

            if (dominoes[index] == 'L' && index - 1 >= 0 && dominoes[index - 1] == '.')
            {
                dominoes[index - 1] = 'L';
                q.push(index - 1);
            }
            else if (dominoes[index] == 'R')
            {
                if (index + 1 < n && dominoes[index + 1] == '.')
                {
                    if (index + 2 < n && dominoes[index + 2] == 'L')
                    {
                        q.pop(); // skipping index + 1, so that it doesn't get changed to 'L' in next iteration
                    }
                    else
                    {
                        q.push(index + 1);
                        dominoes[index + 1] = 'R';
                    }
                }
            }
        }

        return dominoes;
    }
};