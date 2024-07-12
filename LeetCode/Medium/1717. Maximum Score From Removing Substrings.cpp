// Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

class Solution {
public:
   
int maximumGain(string s, int x, int y) {
        int maxPoints = 0;

        // Function to remove the substring and return points using a stack-like approach
        auto removeSubstring = [&](const string &pattern, int points) -> int {
            int score = 0;
            string temp = "";
            for (char c : s) {
                temp.push_back(c);
                int len = temp.size();
                if (len >= 2 && temp[len - 2] == pattern[0] && temp[len - 1] == pattern[1]) {
                    temp.pop_back();
                    temp.pop_back();
                    score += points;
                }
            }
            s = temp;
            return score;
        };

        if (x > y) {
            maxPoints += removeSubstring("ab", x);
            maxPoints += removeSubstring("ba", y);
        } else {
            maxPoints += removeSubstring("ba", y);
            maxPoints += removeSubstring("ab", x);
        }

        return maxPoints;
    }
};
