// Link: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Graph representation
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Max-heap priority queue
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start);

        // Vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we have reached the end node, return the probability
            if (node == end) {
                return prob;
            }

            // Visit each neighbor
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                // If a path with a higher probability is found
                if (prob * edgeProb > maxProb[nextNode]) {
                    maxProb[nextNode] = prob * edgeProb;
                    pq.emplace(maxProb[nextNode], nextNode);
                }
            }
        }

        // If the end node is unreachable
        return 0.0;
    }
};
