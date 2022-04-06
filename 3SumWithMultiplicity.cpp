#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());

        int ans = 0;
        int mod = (pow(10, 9) + 7);

        for (int i = 0; i < arr.size(); i++)
        {
            int temp = target - arr[i];

            int l = i + 1;
            int r = arr.size() - 1;

            while (l < r)
            {
                if (arr[l] + arr[r] == temp)
                {
                    int count1 = 1, count2 = 1;

                    while (l + 1 <= r && arr[l] == arr[l + 1])
                    {
                        l++;
                        count1++;
                    }

                    while (l <= r - 1 && arr[r] == arr[r - 1])
                    {
                        r--;
                        count2++;
                    }

                    // When 2nd and 3rd element are same;
                    if (l == r)
                    {
                        int t = max(count1, count2);
                        ans %= mod;
                        ans += (t * (t - 1)) / 2;
                    }
                    else
                    {
                        ans += count1 * count2;
                    }

                    l++;
                    r--;
                }
                else if (arr[l] + arr[r] > temp)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        return ans % mod;
    }
};