#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> scores;

        for (string op : ops)
        {
            if (op == "+" && scores.size() >= 2)
            {
                int x = scores[scores.size() - 1];
                int y = scores[scores.size() - 2];
                scores.push_back(x + y);
            }
            else if (op == "D" && scores.size() > 0)
            {
                int x = scores[scores.size() - 1];
                scores.push_back(x * 2);
            }
            else if (op == "C" && scores.size() > 0)
            {
                scores.pop_back();
            }
            else
            {
                scores.push_back(stoi(op));
            }
        }

        int ans = 0;

        for (auto x : scores)
            ans += x;

        return ans;
    }
};