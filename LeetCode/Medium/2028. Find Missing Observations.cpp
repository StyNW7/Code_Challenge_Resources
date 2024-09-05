// Link: https://leetcode.com/problems/find-missing-observations/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (n + m);  // Total sum for n + m rolls
        int knownSum = std::accumulate(rolls.begin(), rolls.end(), 0);  // Sum of known rolls
        int missingSum = totalSum - knownSum;  // Sum we need to distribute among missing rolls
        
        // Each missing roll must be between 1 and 6, so the total missing sum should be between n and 6 * n
        if (missingSum < n || missingSum > 6 * n) {
            return {};  // Impossible to distribute the missing sum
        }
        
        // Create an array of length n, initially filled with 1
        std::vector<int> result(n, 1);
        missingSum -= n;  // We have assigned 1 to each missing roll, now distribute the rest
        
        // Distribute the remaining missingSum across the n rolls
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add = std::min(5, missingSum);  // We can add up to 5 (because we already have 1 in each roll)
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};
