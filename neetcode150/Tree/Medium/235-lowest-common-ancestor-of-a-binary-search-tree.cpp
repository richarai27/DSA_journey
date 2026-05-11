// ═══════════════════════════════════════════════════════
// Problem: 235. Lowest Common Ancestor of a Binary Search Tree
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Runtime: 19 ms (Beats 85.5%)
// Memory: 23.5 MB (Beats 64.2%)
// Submitted: May 11, 2026
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// ═══════════════════════════════════════════════════════

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while(cur){
            if(p->val > cur->val && q->val > cur->val) cur= cur->right;
            else if(p->val < cur->val && q->val < cur->val) cur= cur->left;
            else return cur;
        }
        return NULL;
    }
};
