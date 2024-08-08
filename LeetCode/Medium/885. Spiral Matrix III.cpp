// Link: https://leetcode.com/problems/spiral-matrix-iii/description/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        vector<int> steps = {1, 1}; // initial steps for right and down
        int totalCells = rows * cols;
        int directionIndex = 0;

        result.push_back({rStart, cStart}); // start from the initial position
        int stepsCount = 0;
        
        while (result.size() < totalCells) {
            int currentSteps = steps[stepsCount % 2];
            
            for (int i = 0; i < currentSteps; ++i) {
                rStart += directions[directionIndex][0];
                cStart += directions[directionIndex][1];
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
            }
            
            directionIndex = (directionIndex + 1) % 4; // change direction
            stepsCount++;
            
            if (stepsCount % 2 == 0) {
                steps[0]++;
                steps[1]++;
            }
        }
        
        return result;
    }
};
