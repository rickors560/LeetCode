#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses1(string s)
    {
        stack<int> st;
        int result = 0;

        st.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (c == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();

                if (!st.empty())
                    result = max(result, i - st.top());
                else
                    st.push(i);
            }
        }

        return result;
    }

    int longestValidParentheses(string s)
    {
        int result = 0, left = 0, right = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                result = max(result, 2 * left);
            else if (right >= left)
                left = right = 0;
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                result = max(result, 2 * left);
            else if (left >= right)
                left = right = 0;
        }

        return result;
    }
};