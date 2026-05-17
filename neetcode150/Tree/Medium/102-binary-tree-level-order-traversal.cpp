// ═══════════════════════════════════════════════════════
// Problem: 102. Binary Tree Level Order Traversal
// Difficulty: Medium
// Topics: Tree, Breadth-First Search, Binary Tree
// Runtime: 0 ms (Beats 100.0%)
// Memory: 17 MB (Beats 89.8%)
// Submitted: May 18, 2026
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> levelValues;

            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur){
                    levelValues.push_back(cur->val);
                    que.push(cur->left);
                    que.push(cur->right);
                }
            }
            if(!levelValues.empty()) res.push_back(levelValues);
        }
        return res;
    }
};
