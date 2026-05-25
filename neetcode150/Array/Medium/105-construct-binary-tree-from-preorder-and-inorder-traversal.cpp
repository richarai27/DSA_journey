// ═══════════════════════════════════════════════════════
// Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
// Difficulty: Medium
// Topics: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
// Runtime: 19 ms (Beats 9.0%)
// Memory: 74.5 MB (Beats 6.4%)
// Submitted: May 25, 2026
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftpre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> rightpre(preorder.begin()+mid+1, preorder.end());
        vector<int> leftin(inorder.begin(), inorder.begin()+mid);
        vector<int> rightin(inorder.begin()+mid+1, inorder.end());
        
        root->left = buildTree(leftpre, leftin);
        root->right = buildTree(rightpre, rightin);
        return root;
    }
};
