#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // For this refer https://leetcode.com/problems/largest-rectangle-in-histogram/ [Largest Rectangle in Histogram]
    int getMaxAreaOfRectangleInHistogram(vector<int> &histogram)
    {
        int n = histogram.size();
        stack<int> st;
        int area = 0;

        // After n-1, we can still process the elements in the stack
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || histogram[st.top()] >= histogram[i]))
            {
                int height = histogram[st.top()]; // Max height to form a rectangle
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

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> histogram(cols, 0);
        int area = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; row++)
            {
                if (matrix[row][col] == '0')
                    histogram[col] = 0;
                else
                    histogram[col]++;
            }

            area = max(area, getMaxAreaOfRectangleInHistogram(histogram));
        }

        return area;
    }
};