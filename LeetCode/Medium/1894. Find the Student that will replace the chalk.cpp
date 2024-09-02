// Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate the total chalk used in one full round
        long long total_chalk = std::accumulate(chalk.begin(), chalk.end(), 0LL);

        // Step 2: Reduce k modulo the total chalk needed for one round
        k %= total_chalk;

        // Step 3: Determine the student who will need to replace the chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i; // This student cannot be assigned chalk and needs to replace it
            }
            k -= chalk[i];
        }

        return -1; // This line should never be reached
    }
};
