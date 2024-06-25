// Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

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
    int runningSum = 0;
    
    void convertBST(TreeNode* node) {
        if (node == NULL) return;

        // Traverse the right subtree first
        convertBST(node->right);
        
        // Update the current node's value
        runningSum += node->val;
        node->val = runningSum;
        
        // Traverse the left subtree
        convertBST(node->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        convertBST(root);
        return root;
    }
};
