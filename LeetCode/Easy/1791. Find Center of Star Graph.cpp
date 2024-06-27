// Link: https://leetcode.com/problems/find-center-of-star-graph/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    // Since it's a star graph, the center node will appear in the first two edges
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
}
};
