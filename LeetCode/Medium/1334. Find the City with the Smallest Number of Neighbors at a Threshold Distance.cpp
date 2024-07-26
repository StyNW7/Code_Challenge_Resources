// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize the distances with the given edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Set the distance from a city to itself as 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int resultCity = -1;
        int minReachableCities = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            if (reachableCities <= minReachableCities) {
                if (reachableCities < minReachableCities || i > resultCity) {
                    resultCity = i;
                    minReachableCities = reachableCities;
                }
            }
        }

        return resultCity;
    }
};
