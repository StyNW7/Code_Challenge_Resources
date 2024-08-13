// Link: https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // Skip duplicates
                continue;
            }
            
            if (candidates[i] > target) {
                // No need to continue if the current number exceeds the target
                break;
            }
            
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};
