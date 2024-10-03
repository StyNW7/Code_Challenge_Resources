// Link: https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();
    
        int totalSum = accumulate(nums.begin(), nums.end(), 0LL) % p;
        
        if (totalSum == 0) return 0;
        
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  
        int prefixSum = 0;
        int minLength = n;  
        
        for (int i = 0; i < n; ++i) {
            
            prefixSum = (prefixSum + nums[i]) % p;
            
            int targetMod = (prefixSum - totalSum + p) % p;
            
            if (prefixMod.find(targetMod) != prefixMod.end()) {
                minLength = min(minLength, i - prefixMod[targetMod]);
            }
            
            prefixMod[prefixSum] = i;
        }
        
        return minLength == n ? -1 : minLength;
    }
};
