// ═══════════════════════════════════════════════════════
// Problem: 1544. Count Good Nodes in Binary Tree
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Runtime: 90 ms (Beats 83.8%)
// Memory: 88.3 MB (Beats 83.7%)
// Submitted: May 19, 2026
// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxValue){
        if(!root) return 0;

        int res = (root->val >= maxValue) ? 1 : 0;
        maxValue = max(maxValue, root->val);
        res += dfs(root->left, maxValue);
        res += dfs(root->right, maxValue);
        return res;
    }
};
