// Link: https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

struct State {
    int node;
    int time;
};

class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Build the graph
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> minTime(n + 1, INT_MAX);
        vector<int> secondMinTime(n + 1, INT_MAX);
        
        queue<State> q;
        q.push({1, 0}); // Start from vertex 1 at time 0
        minTime[1] = 0;
        
        while (!q.empty()) {
            State current = q.front();
            q.pop();
            
            int node = current.node;
            int currentTime = current.time;
            
            for (int neighbor : graph[node]) {
                // Calculate the time taken to reach the neighbor
                int newTime = currentTime;
                
                if ((newTime / change) % 2 == 1) {
                    // Currently in red signal period, wait until it turns green
                    newTime = (newTime / change + 1) * change;
                }
                
                newTime += time;
                
                if (newTime < minTime[neighbor]) {
                    secondMinTime[neighbor] = minTime[neighbor];
                    minTime[neighbor] = newTime;
                    q.push({neighbor, newTime});
                } else if (newTime > minTime[neighbor] && newTime < secondMinTime[neighbor]) {
                    secondMinTime[neighbor] = newTime;
                    q.push({neighbor, newTime});
                }
            }
        }
        
        return (secondMinTime[n] == INT_MAX) ? -1 : secondMinTime[n];
    }
};
