#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Refer https://www.youtube.com/watch?v=Ty8EZlxVNC8

    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> availabilityMap;
        unordered_map<int, int> vacancyMap;

        for (int i : nums)
            availabilityMap[i]++;

        for (int i : nums)
        {
            if (availabilityMap[i] <= 0)
                continue;
            else if (vacancyMap[i] > 0) // If i can be part of existing subsequence
            {
                availabilityMap[i]--;
                vacancyMap[i]--;

                vacancyMap[i + 1]++; // Creating new Vacancy
            }
            else if (availabilityMap[i] > 0 && availabilityMap[i + 1] > 0 && availabilityMap[i + 2] > 0) // Creating a new subsequence
            {
                availabilityMap[i]--;
                availabilityMap[i + 1]--;
                availabilityMap[i + 2]--;

                vacancyMap[i + 3]++; // For any further element we are creating a vacancy
            }
            else
                return false;
        }

        return true;
    }
};