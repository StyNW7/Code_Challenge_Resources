// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1; // Base case: one way to have a count of zero odd numbers
        int currentOddCount = 0;
        int result = 0;

        for (int num : nums) {
            // Increment the current odd number count if the current number is odd
            if (num % 2 != 0) {
                currentOddCount++;
            }
            // If there exists a prefix with (currentOddCount - k) odd numbers,
            // it means there are 'countMap[currentOddCount - k]' subarrays ending at this position
            // which have exactly 'k' odd numbers
            if (countMap.find(currentOddCount - k) != countMap.end()) {
                result += countMap[currentOddCount - k];
            }
            // Increment the count of the current odd number count in the map
            countMap[currentOddCount]++;
        }

        return result;
    }
};
