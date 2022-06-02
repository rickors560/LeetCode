#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes1(string s, int k)
    {
        if (k > s.size())
            return false;

        set<string> comb;
        int totalNumberOfCombination = 1 << k; // 2^k

        for (int i = 0; i <= s.size() - k; i++)
        {
            comb.insert(s.substr(i, k));

            if (comb.size() == totalNumberOfCombination)
                return true;
        }

        return false;
    }

    // Rolling hash
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;

        int totalNumberOfCombination = 1 << k; // 2^k

        vector<bool> seen(totalNumberOfCombination);

        int allOne = totalNumberOfCombination - 1; // for hash to be in range of k bits (111111.... up to k bits)

        int hash = 0;

        for (int i = 0; i < s.size(); i++)
        {
            // binary string to decimal value in int
            hash = ((hash << 1) & allOne) | (s[i] - '0'); // rolling hash from old hash ( 110 -> 101 )

            if (i >= k - 1 && !seen[hash])
            {
                seen[hash] = true;

                totalNumberOfCombination--;

                if (totalNumberOfCombination == 0)
                    return true;
            }
        }

        return false;
    }
};