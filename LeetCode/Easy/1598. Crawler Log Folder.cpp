// Link: https://leetcode.com/problems/crawler-log-folder/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const std::string& log : logs) {
            if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else if (log != "./") {
                depth++;
            }
        }
        return depth;
    }
};
