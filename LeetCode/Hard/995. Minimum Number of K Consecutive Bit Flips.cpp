// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> flipQueue; // To track flips
        int flips = 0;

        for (int i = 0; i < n; ++i) {
            // Remove flips that are out of the window
            if (!flipQueue.empty() && flipQueue.front() + k <= i) {
                flipQueue.pop();
            }

            // Determine the effective value of nums[i]
            bool flipped = flipQueue.size() % 2 == 1;
            if (flipped) {
                nums[i] ^= 1;
            }

            // If the current value is 0, we need to flip starting from this index
            if (nums[i] == 0) {
                // If flipping k bits from the current index exceeds the array boundary, return -1
                if (i + k > n) {
                    return -1;
                }

                // Apply a flip starting at this index
                flipQueue.push(i);
                nums[i] = 1; // Flip the current bit
                flips++;
            }
        }

        return flips;
    }
};
