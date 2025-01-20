// Link: https://leetcode.com/problems/first-completely-painted-row-or-column/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();    // Number of rows
        int n = mat[0].size(); // Number of columns
        
        // Maps to store row and column counts of painted cells
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Map each value in mat to its position (row, col)
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Iterate through arr and paint the corresponding cell in mat
        for (int i = 0; i < arr.size(); ++i) {
            int value = arr[i];
            auto [r, c] = pos[value];
            
            // Increment the painted cell count for the row and column
            rowCount[r]++;
            colCount[c]++;
            
            // Check if the row or column is fully painted
            if (rowCount[r] == n || colCount[c] == m) {
                return i; // Return the index of the current operation
            }
        }
        
        return -1; // This should not be reached since a full row/column is guaranteed
    }
};
