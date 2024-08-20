// Link: https://leetcode.com/problems/stone-game-ii/description/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        // Calculate suffix sum array
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Fill the dp table
        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                    dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][max(M, X)]);
                }
            }
        }

        // The result is the max stones Alice can get starting from the first pile with M = 1
        return dp[0][1];
    }
};
