// Link: https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        // Iterate through each possible middle soldier
        for (int j = 1; j < n - 1; ++j) {
            int leftLess = 0, leftGreater = 0;
            int rightLess = 0, rightGreater = 0;

            // Count soldiers on the left side of j
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    leftLess++;
                } else if (rating[i] > rating[j]) {
                    leftGreater++;
                }
            }

            // Count soldiers on the right side of j
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    rightLess++;
                } else if (rating[k] > rating[j]) {
                    rightGreater++;
                }
            }

            // For each valid middle soldier, calculate the number of valid teams
            count += leftLess * rightGreater + leftGreater * rightLess;
        }

        return count;
    }
};
