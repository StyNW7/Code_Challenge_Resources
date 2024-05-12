// Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort (happiness.begin(), happiness.end(), greater<int>());
        int i = 0;
        long long ans = 0;

        while (k--){
            happiness[i] = max (happiness[i]-i, 0);
            ans += happiness[i++];
        }

        return ans;
    }
};
