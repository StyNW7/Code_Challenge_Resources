// Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int numRows = rowSum.size();
    int numCols = colSum.size();
    
    // Initialize the result matrix with zeros
    vector<vector<int>> result(numRows, vector<int>(numCols, 0));
    
    // Iterate through each cell of the matrix
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            // Fill the cell with the minimum of the current row sum and column sum
            result[i][j] = min(rowSum[i], colSum[j]);
            
            // Subtract the filled value from the row sum and column sum
            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];
        }
    }
    
    return result;
}
};
