// Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> queue;

        for (int num : nums) queue.push(num);

        long long score = 0;

        while (k > 0){
            int pop = queue.top();
            queue.pop();
            score += pop;
            queue.push(ceil(pop/3.0));
            k--;
        }

        return score;

    }
};
