#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != val)
      {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }
};

int main()
{
  vector<int> t = {3, 2, 2, 3};
  int x = removeElement(t, 3);
  return 0;
}
