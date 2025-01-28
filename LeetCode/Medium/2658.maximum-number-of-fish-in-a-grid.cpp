// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    // Check if the current cell is out of bounds or already visited or a land cell
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] || grid[r][c] == 0) {
        return 0;
    }

    // Mark the current cell as visited
    visited[r][c] = true;

    // Catch all the fish in the current cell
    int fishCount = grid[r][c];

    // Explore the adjacent cells
    fishCount += dfs(r + 1, c, grid, visited); // Down
    fishCount += dfs(r - 1, c, grid, visited); // Up
    fishCount += dfs(r, c + 1, grid, visited); // Right
    fishCount += dfs(r, c - 1, grid, visited); // Left

    return fishCount;
}


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Iterate through all the cells in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the cell is a water cell, perform DFS
                if (grid[i][j] > 0) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    maxFish = max(maxFish, dfs(i, j, grid, visited));
                }
            }
        }

        return maxFish;
    }
};
