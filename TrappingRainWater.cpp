#include <bits/stdc++.h>
using namespace std;

// <============================================> Using two pointers <============================================>

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;

        int answer = 0;

        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    answer += leftMax - height[l]; // this works because height[l] <= height[r]
                l++;
            }

            else
            {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    answer += rightMax - height[r];
                r--;
            }
        }

        return answer;
    }
};

// <============================================> Using prefix max and suffix max <============================================>

class Solution1
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> prefixMax(n); // for left max height
        vector<int> suffixMax(n); // for right max height

        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
            suffixMax[n - i - 1] = max(suffixMax[n - i], height[n - i - 1]);
        }

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            answer += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return answer;
    }
};