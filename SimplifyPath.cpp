#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.length();
        vector<string> stck;

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
                continue;

            string s;

            int j = i;
            while (j < n && path[j] != '/')
            {
                s += path[j];
                j++;
            }
            i = j;

            if (s == ".")
            {
                continue;
            }
            else if (s == "..")
            {
                if (!stck.empty())
                {
                    stck.pop_back();
                }
                continue;
            }
            else if (s.size() > 0)
            {
                stck.push_back(s);
            }
        }

        string ans = "";

        for (auto x : stck)
        {
            ans += "/" + x;
        }
        return ans.size() == 0 ? "/" : ans;
    }
};