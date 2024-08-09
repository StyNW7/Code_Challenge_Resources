// Link: https://leetcode.com/problems/magic-squares-in-grid/description/

bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
    unordered_set<int> seen;

    // Check if all numbers from 1 to 9 are present
    for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
            if (grid[i][j] < 1 || grid[i][j] > 9 || seen.count(grid[i][j])) {
                return false;
            }
            seen.insert(grid[i][j]);
        }
    }

    // Check the sum of each row, column, and diagonals
    int sum1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
    int sum2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
    int sum3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
    
    int sum4 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
    int sum5 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
    int sum6 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
    
    int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
    int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];

    return (sum1 == sum2 && sum2 == sum3 &&
            sum3 == sum4 && sum4 == sum5 &&
            sum5 == sum6 && sum6 == diag1 &&
            diag1 == diag2);
}

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Iterate over each possible starting point for a 3x3 subgrid
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    ++count;
                }
            }
        }
        return count;
    }
};
