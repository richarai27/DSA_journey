// ═══════════════════════════════════════════════════════
// Problem: 572. Subtree of Another Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
// Runtime: 0 ms (Beats 100.0%)
// Memory: 29.1 MB (Beats 38.5%)
// Submitted: May 11, 2026
// Link: https://leetcode.com/problems/subtree-of-another-tree/
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        if(sameTree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) ;
        }
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(p && q && p->val == q->val){
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }else{
            return false;
        }
    }
};
