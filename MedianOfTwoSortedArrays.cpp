#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = m;

        while (l <= r)
        {
            int p1 = (l + r) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int l1, l2, r1, r2;

            l1 = p1 == 0 ? INT_MIN : nums1[p1 - 1];
            r1 = p1 == m ? INT_MAX : nums1[p1];

            l2 = p2 == 0 ? INT_MIN : nums2[p2 - 1];
            r2 = p2 == n ? INT_MAX : nums2[p2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 == 0)
                    return ((max(l1, l2) + min(r1, r2)) / 2.0);
                else
                    return max(l1, l2);
            }

            if (l1 > r2)
                r = p1 - 1;
            if (l2 > r1)
                l = p1 + 1;
        }

        return 0;
    }
};