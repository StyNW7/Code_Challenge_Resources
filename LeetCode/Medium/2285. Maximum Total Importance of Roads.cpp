// Link: https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        // Calculate the degree of each city
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Pair each city's degree with its index and sort by degree in descending order
        vector<pair<int, int>> degreeIndex;
        for (int i = 0; i < n; ++i) {
            degreeIndex.emplace_back(degree[i], i);
        }
        sort(degreeIndex.rbegin(), degreeIndex.rend());

        // Assign values from n to 1 based on the degree of the city
        vector<int> values(n);
        int val = n;
        for (const auto& [deg, index] : degreeIndex) {
            values[index] = val--;
        }

        // Calculate the total importance
        long long totalImportance = 0; // Changed to long long
        for (const auto& road : roads) {
            totalImportance += static_cast<long long>(values[road[0]]) + static_cast<long long>(values[road[1]]);
        }

        return totalImportance;
    }
};
