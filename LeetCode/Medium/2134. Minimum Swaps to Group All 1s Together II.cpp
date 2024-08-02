// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

    // Count total number of 1's
    int countOnes = std::count(nums.begin(), nums.end(), 1);

    // If there are no 1's or the entire array is 1's, no swaps needed
    if (countOnes == 0 || countOnes == n) {
        return 0;
    }

    // Extend the array to handle circular nature
    nums.insert(nums.end(), nums.begin(), nums.begin() + countOnes - 1);

    // Find the maximum number of 1's in any window of size countOnes
    int maxOnesInWindow = 0;
    int currentOnes = 0;

    for (int i = 0; i < countOnes; ++i) {
        if (nums[i] == 1) {
            currentOnes++;
        }
    }

    maxOnesInWindow = currentOnes;

    for (int i = countOnes; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            currentOnes++;
        }
        if (nums[i - countOnes] == 1) {
            currentOnes--;
        }
        maxOnesInWindow = std::max(maxOnesInWindow, currentOnes);
    }

    // Minimum swaps required to group all 1's together
    return countOnes - maxOnesInWindow;
    }
};
