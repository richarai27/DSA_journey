// ═══════════════════════════════════════════════════════
// Problem: 230. Kth Smallest Element in a BST
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Runtime: 0 ms (Beats 100.0%)
// Memory: 24.6 MB (Beats 25.7%)
// Submitted: May 24, 2026
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> stack;
        TreeNode* curr = root;

        while(curr || !stack.empty()){
            while(curr){
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            n += 1;
            if(n == k) return curr->val;

            curr = curr->right;
        }
        return 0;
    }
};
