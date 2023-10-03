#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int aliceScore = 0;
        int bobScore = 0;

        for (int i = 1; i < colors.size() - 1; i++)
        {
            char current = colors[i];
            char prev = colors[i - 1];
            char next = colors[i + 1];

            if (current == 'A' && prev == 'A' && next == 'A')
                aliceScore++;

            if (current == 'B' && prev == 'B' && next == 'B')
                bobScore++;
        }

        return aliceScore > bobScore;
    }
};