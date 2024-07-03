// Link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;  // If there are 4 or fewer elements, we can make them all equal with at most 3 moves.

        std::sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            min_diff = std::min(min_diff, nums[n - 4 + i] - nums[i]);
        }
        
        return min_diff;
    }
};
