// Link: https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int size = nums.size();
        stack <int> stack;
        
        for (int i = 0; i < size; i++){
            if (stack.empty() || nums[stack.top()] > nums[i]) stack.push(i);
        }

        int rimp = 0;

        for (int i = size-1; i > 0; i--){
            while (!stack.empty() && nums[stack.top()] <= nums[i]){
                rimp = max (rimp, i - stack.top());
                stack.pop();
            }
        }

        return rimp;

    }
};
