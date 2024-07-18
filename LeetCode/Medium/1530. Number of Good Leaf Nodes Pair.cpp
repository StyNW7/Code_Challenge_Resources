// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    // Helper function to perform DFS and calculate distances between leaf nodes
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        
        if (!node->left && !node->right) {
            // Leaf node case
            return {0};
        }
        
        vector<int> leftLeaves = dfs(node->left, distance, count);
        vector<int> rightLeaves = dfs(node->right, distance, count);
        
        // Collect all distances from this node to leaf nodes in its subtree
        vector<int> distances;
        for (int left : leftLeaves) {
            for (int right : rightLeaves) {
                if (left + right + 2 <= distance) {
                    count++;
                }
            }
            distances.push_back(left + 1);
        }
        for (int right : rightLeaves) {
            distances.push_back(right + 1);
        }
        
        return distances;
    }
};
