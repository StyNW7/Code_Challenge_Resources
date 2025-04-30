// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++){
            if (nums[i] >= 10 && nums[i] < 100) total++;
            else if (nums[i] >= 1000 && nums[i] < 10000) total++;
            else if (nums[i] >= 100000 && nums[i] < 1000000) total++;
            else if (nums[i] >= 10000000 && nums[i] < 100000000) total++;
        }
        return total;
    }
};
