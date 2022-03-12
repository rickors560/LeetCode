#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool isPositive = true;

        int index = 0;
        while(index < s.size() && s[index] == ' '){
            index++;
        }

        if(s[index] == '+'){
            isPositive = true;
            index++;
        }
        else if(s[index] == '-'){
            isPositive = false;
            index++;
        }

        int result = 0;
        while (index < s.size() && isdigit(s[index]) ){
            int digit = s[index] - '0';

            if( (result > INT_MAX/10 )||  ( result == INT_MAX / 10 && digit > INT_MAX % 10 ) ){
                return isPositive ? INT_MAX : INT_MIN;
            }

            result = result*10 + digit;
            index++;
        }

        if(!isPositive){
            result = -1 * result;
        }

        return  result;
    }
};