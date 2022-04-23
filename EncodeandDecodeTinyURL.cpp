#include <bits/stdc++.h>

using namespace std;

class Solution
{
    string baseUrl = "http://tinyurl.com/";

    unordered_map<string, string> lookUp;

    // Polynomial rolling hash function for string
    long long computeHash(string str)
    {
        const int p = 3;
        const int m = 100000009;

        long long hash = 0;
        long long pow = 1;
        for (char character : str)
        {
            hash += ((character - 'a' + 1) * pow) % m;
            pow = ((pow * p) % m);
        }

        return hash;
    }

public:
    string encode(string longUrl)
    {
        long long hash = computeHash(longUrl);
        string shortUrl = baseUrl + to_string(hash);
        lookUp[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl)
    {
        return lookUp[shortUrl];
    }
};