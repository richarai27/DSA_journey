// ═══════════════════════════════════════════════════════
// Problem: 199. Binary Tree Right Side View
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Runtime: 3 ms (Beats 7.4%)
// Memory: 15 MB (Beats 40.3%)
// Submitted: May 18, 2026
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode* rightElement = nullptr;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr){
                    rightElement = curr;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(rightElement) result.push_back(rightElement->val);
        }
        return result;
    }
};
