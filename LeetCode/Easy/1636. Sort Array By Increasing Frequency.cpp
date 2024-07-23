// Link: https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        // Calculate the frequency of each element in nums
        for (int num : nums) {
            freq[num]++;
        }

        // Custom comparator for sorting
        auto comparator = [&freq](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b; // Sort in decreasing order if frequencies are the same
            }
            return freq[a] < freq[b]; // Sort in increasing order of frequencies
        };

        // Sort the array using the custom comparator
        std::sort(nums.begin(), nums.end(), comparator);

        return nums;
    }
};
