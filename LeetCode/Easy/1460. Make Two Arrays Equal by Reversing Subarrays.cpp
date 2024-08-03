// Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        
        // Check if sorted arrays are equal
        return target == arr;
    }
};
