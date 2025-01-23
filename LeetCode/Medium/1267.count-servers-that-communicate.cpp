// Link: https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size(); // number of rows
        int n = grid[0].size(); // number of columns

        vector<int> row_count(m, 0); // Count of servers in each row
        vector<int> col_count(n, 0); // Count of servers in each column

        // Count the servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        int count = 0;

        // Count servers that can communicate
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
        
    }
};
