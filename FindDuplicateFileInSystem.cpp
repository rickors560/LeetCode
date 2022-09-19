#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> split(string str, char delimiter)
    {
        vector<string> result;
        stringstream stream(str);
        string item;

        while (getline(stream, item, delimiter))
        {
            if (item.length() > 0)
                result.push_back(item);
        }

        return result;
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < paths.size(); i++)
        {
            string path = paths[i];
            auto files = split(path, ' ');

            string basePath = files[0];

            for (int j = 1; j < files.size(); j++)
            {
                string file = files[j];
                string content = file.substr(file.find('('), file.find(')') - file.find('(') + 1);
                string temp = basePath + "/" + file;
                temp.replace(temp.find(content), content.size(), "");
                mp[content].push_back(temp);
            }
        }

        for (auto entry : mp)
        {
            if (entry.second.size() > 1)
            {
                result.push_back(entry.second);
            }
        }

        return result;
    }
};