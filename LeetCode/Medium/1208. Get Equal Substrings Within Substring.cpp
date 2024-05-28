// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int start = 0, maxLength = 0, currentCost = 0;
        
        for (int end = 0; end < len; end++) {
            currentCost += abs(s[end] - t[end]);
            
            // If the cost exceeds maxCost, shrink the window from the start
            while (currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                start++;
            }
            
            // Update the maximum length of the substring found
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
