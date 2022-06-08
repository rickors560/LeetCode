#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Sub-array need to be consecutive.
    // Subsequence don't have to be consecutive.

    // So we have 2 cases - if s is already a palindrome then result is 1,
    // else result is 2 as 1 operation to remove all 'a's and another 1 operation to remove all 'b's.

    int removePalindromeSub(string s)
    {
        if (s.empty())
            return 0;

        return equal(s.begin(), s.end(), s.rbegin()) ? 1 : 2;
    }
};