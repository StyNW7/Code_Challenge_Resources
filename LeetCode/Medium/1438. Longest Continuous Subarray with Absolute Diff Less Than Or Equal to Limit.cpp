class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeque, maxDeque;
        int left = 0, right;
        int maxLength = 0;
        
        for (right = 0; right < nums.size(); ++right) {
            while (!minDeque.empty() && nums[right] < nums[minDeque.back()]) {
                minDeque.pop_back();
            }
            while (!maxDeque.empty() && nums[right] > nums[maxDeque.back()]) {
                maxDeque.pop_back();
            }
            
            minDeque.push_back(right);
            maxDeque.push_back(right);
            
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                ++left;
                if (minDeque.front() < left) minDeque.pop_front();
                if (maxDeque.front() < left) maxDeque.pop_front();
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
