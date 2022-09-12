#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int left = 0, right = tokens.size() - 1;
        int currentScore = 0;

        while (left <= right && (power >= tokens[left] || currentScore > 0))
        {
            while (left <= right && power >= tokens[left])
            {
                power -= tokens[left]; // Losing lowest power
                currentScore++;

                left++;
            }

            score = max(score, currentScore);

            if (left <= right && currentScore > 0)
            {
                power += tokens[right--]; // Adding Highest power
                currentScore--;
            }
        }

        return score;
    }
};