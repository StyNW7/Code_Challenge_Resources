// Link: https://leetcode.com/problems/sort-the-people/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        // Create a vector of pairs where each pair contains a name and its corresponding height
        std::vector<std::pair<int, std::string>> heightNamePairs;

        for (int i = 0; i < n; ++i) {
            heightNamePairs.push_back({heights[i], names[i]});
        }

        // Sort the pairs by heights in descending order
        std::sort(heightNamePairs.begin(), heightNamePairs.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
            return a.first > b.first;
        });

        // Extract the sorted names
        std::vector<std::string> sortedNames;
        for (const auto& pair : heightNamePairs) {
            sortedNames.push_back(pair.second);
        }

        return sortedNames;
    }
};
