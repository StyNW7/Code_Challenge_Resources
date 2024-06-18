// Link: https://leetcode.com/problems/most-profit-assigning-work/description/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Create a vector of pairs (difficulty, profit)
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());

        // Sort worker by their abilities
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int bestProfit = 0;
        int jobIndex = 0;
        int m = worker.size();

        // Iterate through each worker
        for (int i = 0; i < m; ++i) {
            // Find the best job that the current worker can do
            while (jobIndex < n && worker[i] >= jobs[jobIndex].first) {
                bestProfit = max(bestProfit, jobs[jobIndex].second);
                ++jobIndex;
            }
            // Add the best profit for the current worker
            maxProfit += bestProfit;
        }

        return maxProfit;
    }
};
