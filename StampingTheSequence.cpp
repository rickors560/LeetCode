#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int fetchStampIndex(string &str, string &stamp)
    {
        for (int i = 0; i <= str.size() - stamp.size(); i++)
        {
            int stampIndex = 0;
            int strIndex = i;
            bool isNonStarChar = false;
            while (stampIndex < stamp.size() && strIndex < str.size() && (str[strIndex] == '*' || str[strIndex] == stamp[stampIndex]))
            {
                if (str[strIndex] != '*') // To skip all star substring as we dont need to restamp it again
                    isNonStarChar = true;

                stampIndex++;
                strIndex++;
            }

            if (stampIndex == stamp.size() && isNonStarChar)
                return i;
        }

        return -1;
    }

    void updateStr(string &str, int stampIndex, string &stamp)
    {
        for (int i = 0; i < stamp.size(); i++)
        {
            str[stampIndex + i] = '*';
        }
    }

public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> result;
        string str = target;
        string targetString(target.size(), '*');        //Think in reverse like target -> '********'

        while (str != targetString)
        {
            int stampIndex = fetchStampIndex(str, stamp);

            if (stampIndex < 0)
                return {};
            else
                updateStr(str, stampIndex, stamp);

            result.push_back(stampIndex);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};