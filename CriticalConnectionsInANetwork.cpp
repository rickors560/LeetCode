#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int time = 1;
    unordered_map<int, vector<int>> adj;
    vector<int> low, disc; // low (low-link) => smallest node reachable from that node & disc => discovery time for that node;

    vector<vector<int>> result;

    // Tarjan's algorithm for Strongly Connected Components(SCCs)
    void dfs(int current, int prev)
    {
        disc[current] = time;
        low[current] = time;

        time++;

        for (int next : adj[current])
        {
            if (disc[next] == 0) // next is not visited
            {
                dfs(next, current);
                low[current] = min(low[current], low[next]);
            }
            else if (next != prev)
            {
                low[current] = min(low[current], disc[next]); // current node can be reached earlier to next node and we update its low with next node disc
            }

            if (low[next] > disc[current])
                result.push_back({current, next});
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        low = vector<int>(n);
        disc = vector<int>(n);

        dfs(0, -1);

        return result;
    }
};