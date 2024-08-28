// Link: https://leetcode.com/problems/count-sub-islands/

// Function to perform DFS and check if the island in grid2 is a sub-island
bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 0) {
        return true;
    }

    // If this cell is part of the island in grid2 but not in grid1, it's not a sub-island
    if (grid1[i][j] == 0) return false;

    // Mark the cell in grid2 as visited
    grid2[i][j] = 0;

    // Explore all four directions
    bool up = dfs(grid1, grid2, i - 1, j);
    bool down = dfs(grid1, grid2, i + 1, j);
    bool left = dfs(grid1, grid2, i, j - 1);
    bool right = dfs(grid1, grid2, i, j + 1);

    // Return true only if all the parts of this island in grid2 are contained in grid1
    return up && down && left && right;
}


class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int subIslandsCount = 0;

        // Iterate over grid2 to find all islands
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    // If the DFS returns true, the island is a sub-island
                    if (dfs(grid1, grid2, i, j)) {
                        subIslandsCount++;
                    }
                }
            }
        }

        return subIslandsCount;
    }
};
