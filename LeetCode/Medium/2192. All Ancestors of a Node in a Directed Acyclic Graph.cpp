// Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Step 1: Build the graph
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Step 2: Topological sorting using Kahn's algorithm (BFS)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for (int neighbor : graph[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Track ancestors
        vector<set<int>> ancestors(n);
        for (int node : topoOrder) {
            for (int neighbor : graph[node]) {
                ancestors[neighbor].insert(node);
                for (int ancestor : ancestors[node]) {
                    ancestors[neighbor].insert(ancestor);
                }
            }
        }

        // Step 4: Convert sets to sorted vectors
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};
