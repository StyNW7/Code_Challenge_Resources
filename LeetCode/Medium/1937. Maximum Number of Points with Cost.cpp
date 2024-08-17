// Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(n, 0);

        // Initial dp array is just the first row's values
        for (int c = 0; c < n; ++c) {
            dp[c] = points[0][c];
        }

        // Iterate through each row, updating the dp array
        for (int r = 1; r < m; ++r) {
            // Arrays to store maximum values from the left and right directions
            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            // Fill the left max values
            left[0] = dp[0];
            for (int c = 1; c < n; ++c) {
                left[c] = max(left[c - 1] - 1, dp[c]);
            }

            // Fill the right max values
            right[n - 1] = dp[n - 1];
            for (int c = n - 2; c >= 0; --c) {
                right[c] = max(right[c + 1] - 1, dp[c]);
            }

            // Update dp array for the current row
            for (int c = 0; c < n; ++c) {
                dp[c] = points[r][c] + max(left[c], right[c]);
            }
        }

        // The answer is the maximum value in the dp array after processing all rows
        return *max_element(dp.begin(), dp.end());
    }
};
