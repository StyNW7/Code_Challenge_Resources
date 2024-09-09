// Link: https://leetcode.com/problems/spiral-matrix-iv

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Create an m x n matrix initialized with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Directions for moving right, down, left, and up (spiral order)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int dir = 0; // start by moving right
        int row = 0, col = 0; // starting position
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        ListNode* curr = head; // pointer to traverse the linked list
        
        while (curr) {
            matrix[row][col] = curr->val; // fill matrix with current list value
            curr = curr->next; // move to the next node
            
            // Move in the current direction
            int nextRow = row + directions[dir].first;
            int nextCol = col + directions[dir].second;
            
            // Check if we need to change direction (boundary condition)
            if (nextRow < top || nextRow > bottom || nextCol < left || nextCol > right) {
                // Change the boundaries and direction
                if (dir == 0) top++; // moved right, so top boundary decreases
                else if (dir == 1) right--; // moved down, so right boundary decreases
                else if (dir == 2) bottom--; // moved left, so bottom boundary decreases
                else if (dir == 3) left++; // moved up, so left boundary increases
                
                // Change direction (right -> down -> left -> up)
                dir = (dir + 1) % 4;
                
                // Update the new direction's row and col
                nextRow = row + directions[dir].first;
                nextCol = col + directions[dir].second;
            }
            
            // Move to the next position
            row = nextRow;
            col = nextCol;
        }
        
        return matrix;
    }
};
