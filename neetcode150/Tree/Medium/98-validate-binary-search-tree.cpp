// ═══════════════════════════════════════════════════════
// Problem: 98. Validate Binary Search Tree
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Runtime: 2 ms (Beats 6.4%)
// Memory: 21.9 MB (Beats 43.4%)
// Submitted: May 22, 2026
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
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* root, long left, long right){
        if(!root) return true;

        if(!(root->val > left && root->val < right)){
            return false;
        }else{
            return valid(root->left, left, root->val) && valid(root->right, root->val, right);
        }
    }
};
