// Link: https://leetcode.com/problems/maximum-distance-in-arrays/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        for (int i = 1; i < arrays.size(); ++i) {
            // Check the distance with the current array's smallest and largest values
            maxDist = max(maxDist, abs(arrays[i].back() - minVal));
            maxDist = max(maxDist, abs(maxVal - arrays[i].front()));
            
            // Update minVal and maxVal
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDist;
    }
};
