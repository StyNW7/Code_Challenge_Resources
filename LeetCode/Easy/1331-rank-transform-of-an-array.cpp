// Link: https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector <int> result (arr);
        sort(result.begin(), result.end());

        unordered_map <int, int> rank;

        for (int& a : result) rank.emplace(a, rank.size()+1);

        for (int i = 0; i < result.size(); ++i) result[i] = rank[arr[i]];

        return result;

    }
};
