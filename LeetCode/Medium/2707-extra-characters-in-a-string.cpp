// Link: https://leetcode.com/problems/extra-characters-in-a-string/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        vector<int> dp(n + 1, n);
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i; j < n; ++j) {
                string substr = s.substr(i, j - i + 1);
                if (dict.count(substr)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        
        return dp[0];
        
    }
};
