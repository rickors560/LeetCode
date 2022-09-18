#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int area = 0;

        // After n-1, we can still process the elements in the stack
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()]; // Max height to form a rectangle
                st.pop();

                int width;
                if (st.empty()) // If stack is empty left is 0 anf right is i
                    width = i;
                else
                    width = i - st.top() - 1;
                area = max(area, height * width);
            }
            st.push(i);
        }
        return area;
    }

    int largestRectangleArea1(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;

        vector<int> leftSmall(n);
        vector<int> rightSmall(n);

        for (int i = 0; i < n; i++)
        {
            // Maintaining a strictly increasing stack
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                leftSmall[i] = 0; // No left elements
            else
                leftSmall[i] = st.top() + 1; // Taking last min element

            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightSmall[i] = n - 1; // No right elements
            else
                rightSmall[i] = st.top() - 1; // Taking last min element

            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            area = max(area, heights[i] * (rightSmall[i] - leftSmall[i]));
        }

        return area;
    }
};