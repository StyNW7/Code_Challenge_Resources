// Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

// Helper function to perform depth-first search to check connectivity
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y])
        return;
    
    visited[x][y] = true;
    
    // Explore all four directions
    dfs(grid, visited, x + 1, y);
    dfs(grid, visited, x - 1, y);
    dfs(grid, visited, x, y + 1);
    dfs(grid, visited, x, y - 1);
}

// Function to count the number of islands in the grid
int countIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islandCount = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                ++islandCount;
                dfs(grid, visited, i, j);
            }
        }
    }
    return islandCount;
}

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Check initial number of islands
        if (countIslands(grid) != 1) {
            return 0;  // Already disconnected
        }
        
        // Check if a single cell removal disconnects the island
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    // Temporarily set this land cell to water
                    grid[i][j] = 0;
                    
                    if (countIslands(grid) != 1) {
                        return 1;  // Disconnects by removing one land cell
                    }
                    
                    // Restore the cell
                    grid[i][j] = 1;
                }
            }
        }
        
        // If neither condition above is met, we need at least 2 removals
        return 2;
    }
};
