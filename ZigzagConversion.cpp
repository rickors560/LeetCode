#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        int n = s.length();

        vector<string> rows(numRows, "");

        int currentPosition = 0;
        bool moveUp = false;

        for(int i = 0; i < n; i++){
            rows[currentPosition] += s[i];

            if(currentPosition == 0 || currentPosition == numRows - 1)
                moveUp ^= 1;
            currentPosition +=  moveUp ? 1 : -1;
        }

        string answer = "";
        for(auto row : rows){
            answer += row;
        }

        return answer;
    }
};