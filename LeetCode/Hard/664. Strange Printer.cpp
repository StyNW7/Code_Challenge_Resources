// Link: https://leetcode.com/problems/strange-printer/

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1; // Base case: A single character needs 1 turn
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + 1; // Initialize with worst case
                
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j-1]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
