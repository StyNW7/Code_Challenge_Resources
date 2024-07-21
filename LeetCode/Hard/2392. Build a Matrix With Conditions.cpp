// Link: https://leetcode.com/problems/build-a-matrix-with-conditions/

vector<int> topologicalSort(int k, const vector<vector<int>>& conditions) {
    vector<int> inDegree(k + 1, 0);
    unordered_map<int, vector<int>> graph;

    // Build graph and compute in-degrees
    for (const auto& condition : conditions) {
        int u = condition[0], v = condition[1];
        graph[u].push_back(v);
        inDegree[v]++;
    }

    // Topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if topological sorting is possible (i.e., if we got all nodes)
    if (order.size() == k) {
        return order;
    } else {
        return {};
    }
}

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};  // If sorting failed, return empty matrix
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPosition, colPosition;

        // Map numbers to their positions in the topological order
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        // Place numbers in the matrix according to their positions
        for (int num = 1; num <= k; ++num) {
            matrix[rowPosition[num]][colPosition[num]] = num;
        }

        return matrix;
    }
};
