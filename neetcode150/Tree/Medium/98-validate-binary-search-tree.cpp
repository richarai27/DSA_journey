// ═══════════════════════════════════════════════════════
// Problem: 98. Validate Binary Search Tree
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Runtime: 0 ms (Beats 100.0%)
// Memory: 21.8 MB (Beats 73.3%)
// Submitted: May 24, 2026
// Link: https://leetcode.com/problems/validate-binary-search-tree/
// ═══════════════════════════════════════════════════════

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
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_MIN, LONG_MAX);
    }

    bool validBST(TreeNode* root, long left, long right){
        if(!root) return true;

        if(!(root->val > left && root->val < right)){
            return false;
        }else{
            return validBST(root->left, left, root->val) && validBST(root->right, root->val, right);
        }
    }
};
