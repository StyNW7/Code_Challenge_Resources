// Link: https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> map;

        for (auto& x : s1) map[x]++;

        int right = 0, left = 0, n = s2.length(), required = s1.length();

        while (right < n){
            if (map[s2[right]] > 0) required--;
            map[s2[right]]--;
            right++;

            if (required == 0) return true;

            if (right - left == s1.length()){
                if (map[s2[left]] >= 0) required++;
                map[s2[left]]++;
                left++;
            }
        }

        return false;

    }
};
