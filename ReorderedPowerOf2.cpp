#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> countFreq(int n)
    {
        vector<int> freq(10, 0);

        while (n > 0)
        {
            freq[n % 10]++;
            n /= 10;
        }

        return freq;
    }

    bool isFreqEqual(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] != b[i])
                return false;
        }

        return true;
    }

public:
    bool reorderedPowerOf2(int n)
    {
        auto originalCount = countFreq(n);

        // Since N could only be a power of 2 with 9 digits or less and 10 digits max till 10^9 (fyi -> as int is a 32-bit integer i.e, 2^32)
        for (int i = 0; i < 31; i++)
        {
            auto powerOf2Freq = countFreq(1 << i); // 1 << i  ===> 1*(2^i)  power calculation
            if (isFreqEqual(originalCount, powerOf2Freq))
                return true;
        }

        return false;
    }
};