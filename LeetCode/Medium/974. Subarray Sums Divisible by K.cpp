// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // There is one way to have a prefix sum of 0.
        
        int sum = 0;
        int count = 0;
        
        for (int num : nums) {
            sum += num;
            int remainder = sum % k;
            
            // Ensure the remainder is positive.
            if (remainder < 0) {
                remainder += k;
            }
            
            if (prefixCount.find(remainder) != prefixCount.end()) {
                count += prefixCount[remainder];
            }
            
            prefixCount[remainder]++;
        }
        
        return count;
    }
};
