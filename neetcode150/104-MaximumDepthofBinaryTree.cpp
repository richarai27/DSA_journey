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
    // Approach: Depth First Search (DFS) using recursion
    // Time Complexity: O(n) where n is the number of nodes in the tree
    // Space Complexity: O(h) where h is the height of the tree (due to recursive call stack) 
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (1 + max(leftDepth, rightDepth));
    }
};