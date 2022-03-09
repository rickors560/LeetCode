#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
    string longestPalindrome(string s){
        int n = s.length();

        int max_length = 0;
        string max_s = "";

        for (int i = 0; i < n; i++){

            // For odd length of palindrome, centre will be a single character and from it we expand to left and right
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right] ){
                if(max_length < right - left + 1){
                    max_length = right - left + 1;
                    max_s = s.substr(left, max_length);
                }

                left--;
                right++;
            }

            // For even length of palindrome, centre will be two characters and from there we expand to left and right
            left = i;
            right = i+1;
           while (left >= 0 && right < n && s[left] == s[right] ){
                if(max_length < right - left + 1){
                    max_length = right - left + 1;
                    max_s = s.substr(left, max_length);
                }
                
                left--;
                right++;
            }
        }

        return max_s;        
    }
};