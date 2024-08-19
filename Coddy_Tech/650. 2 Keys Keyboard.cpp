// Link: https://leetcode.com/problems/2-keys-keyboard/description/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i; // Initialize with the worst case, i.e., 'A' repeated i times (copy all, then paste i-1 times).
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    // If j is a factor of i
                    dp[i] = min(dp[i], dp[j] + i / j);
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        
        return dp[n];
    }
};
