#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        stack<int> st;
        int visited[27] = {0};
        int lastIndex[27] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            lastIndex[c] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';

            if (visited[c])
                continue;
            visited[c] = 1;

            while (!st.empty() && st.top() > c && lastIndex[st.top()] > i)
            {
                visited[st.top()] = 0;
                st.pop();
            }
            st.push(c);
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top() + 'a';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};