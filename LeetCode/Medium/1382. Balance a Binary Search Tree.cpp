// Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/

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
    // Helper function to perform in-order traversal and collect nodes.
void inorderTraversal(TreeNode* root, vector<int>& nodes) {
    if (root == nullptr) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
}

// Helper function to build a balanced BST from a sorted array.
TreeNode* buildBalancedBST(vector<int>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorderTraversal(root, nodes);
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
};
