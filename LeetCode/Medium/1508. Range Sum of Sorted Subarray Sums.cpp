// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        std::vector<int> subarraySums;

    // Compute all subarray sums
    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += nums[j];
            subarraySums.push_back(currentSum);
        }
    }

    // Sort the subarray sums
    std::sort(subarraySums.begin(), subarraySums.end());

    // Calculate the sum from index left to right (1-based index)
    long long result = 0;
    for (int k = left - 1; k < right; ++k) {
        result = (result + subarraySums[k]) % MOD;
    }

    return result;
    }
};
