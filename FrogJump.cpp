#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    unordered_map<int, int> stoneToIndex;
    int dp[2000][2000];

    int solve(int stoneIndex, int jumpLength, vector<int> &stones)
    {
        if (stoneIndex == stones.size() - 1)
            return 1;

        if (dp[stoneIndex][jumpLength] != -1)
            return dp[stoneIndex][jumpLength];

        bool k = false;
        bool kp = false;
        bool kn = false;

        if (stoneToIndex.find(stones[stoneIndex] + jumpLength) != stoneToIndex.end())
            k = solve(stoneToIndex[stones[stoneIndex] + jumpLength], jumpLength, stones);

        if (stoneToIndex.find(stones[stoneIndex] + jumpLength + 1) != stoneToIndex.end())
            kp = solve(stoneToIndex[stones[stoneIndex] + jumpLength + 1], jumpLength + 1, stones);

        if (jumpLength > 1 && stoneToIndex.find(stones[stoneIndex] + jumpLength - 1) != stoneToIndex.end())
            kn = solve(stoneToIndex[stones[stoneIndex] + jumpLength - 1], jumpLength - 1, stones);

        dp[stoneIndex][jumpLength] = k || kp || kn;
        return dp[stoneIndex][jumpLength];
    }

public:
    bool canCross(vector<int> &stones)
    {
        if (stones[1] - stones[0] != 1)
            return false;

        for (int i = 0; i < stones.size(); i++)
            stoneToIndex[stones[i]] = i;

        memset(dp, -1, sizeof(dp));

        return solve(1, 1, stones);
    }
};

int main()
{
    cout << "Hello" << endl;
    return 0;
}
