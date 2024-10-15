// Link: https://leetcode.com/problems/separate-black-and-white-balls/

class Solution {
public:
    long long minimumSteps(string s) {
        int size = s.length();
        long long ans = 0;
        int count = 0;

        for (int i = 0; i < size; i++){
            if (s[i] == '0') ans += count;
            else count++;
        }

        return ans;
    }
};
