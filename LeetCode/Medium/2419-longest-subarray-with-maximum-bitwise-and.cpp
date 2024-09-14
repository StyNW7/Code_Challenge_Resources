// Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxValue = *std::max_element(nums.begin(), nums.end());

        int maxLength = 0;
        int currentLength = 0;

        for (int num : nums){
            if (num == maxValue){
                currentLength++;
                maxLength = max(maxLength, currentLength);
            }
            else currentLength = 0;
        }   

        return maxLength;

    }
};
