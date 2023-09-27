#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long decodedSize = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                decodedSize = decodedSize * (s[i] - '0');
            }
            else
            {
                decodedSize++;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isdigit(s[i]))
            {
                decodedSize = decodedSize / (s[i] - '0');
                k = k % decodedSize;
            }
            else
            {
                if (k == 0 || k == decodedSize)
                {
                    ans += s[i];
                    break;
                }
                decodedSize--;
            }
        }

        return ans;
    }
};