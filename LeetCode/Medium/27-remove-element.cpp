// Link: https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int total = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[total] = nums[i];
                total++;
            }
        }

        return total;

    }
};
