// Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<std::string, int> stringCount;
        std::vector<std::string> distinctStrings;

        // Count the occurrences of each string
        for (const auto& str : arr) {
            stringCount[str]++;
        }

        // Collect distinct strings in order
        for (const auto& str : arr) {
            if (stringCount[str] == 1) {
                distinctStrings.push_back(str);
            }
        }

        // Check if k-th distinct string exists
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1]; // k is 1-based
        } else {
            return ""; // Return empty string if there are fewer than k distinct strings
        }
    }
};
