// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> freq1;
        std::unordered_map<int, int> freq2;

        // Count frequencies of each element in nums1
        for (int num : nums1) {
            freq1[num]++;
        }

        // Count frequencies of each element in nums2
        for (int num : nums2) {
            freq2[num]++;
        }

        std::vector<int> result;

        // Find the intersection based on the minimum frequency in both arrays
        for (auto& pair : freq1) {
            int num = pair.first;
            int count1 = pair.second;
            
            if (freq2.find(num) != freq2.end()) {
                int count2 = freq2[num];
                int minCount = std::min(count1, count2);
                
                for (int i = 0; i < minCount; ++i) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};
