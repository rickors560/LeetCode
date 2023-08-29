#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int bestClosingTime(string customers) {
    int max_score = 0;
    int score = 0;
    int best_time = -1;
    
    for(int i = 0; i < customers.size(); i++){
      score += (customers[i] == 'Y') ? 1 : -1;
      
      if(score > max_score){
        max_score = score;
        best_time = i;
      }
    }
    
    return best_time + 1;
  }
};