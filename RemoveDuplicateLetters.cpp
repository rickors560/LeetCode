#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int lastSeenIndexes[26] = {-1};
        for (int i = 0; i < s.length(); i++)
        {
            lastSeenIndexes[s[i] - 'a'] = i;
        }

        stack<int> st;
        bool hasSeen[26] = {false};

        for (int i = 0; i < s.length(); i++)
        {
            int current = s[i] - 'a';
            if (hasSeen[current])
                continue;

            // check if current is in lexicographical order and if not then we pop from stack ( if popped element exists in remaining string by last seen index array )
            while (!st.empty() && st.top() > current && i < lastSeenIndexes[st.top()])
            {
                hasSeen[st.top()] = false;
                st.pop();
            }

            st.push(current);
            hasSeen[current] = true;
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top() + 'a';
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};