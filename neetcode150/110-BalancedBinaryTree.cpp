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
    // Determining tree balance by computing height and validity status simultaneously during a post-order      traversal.
    // Time: O(n) where n is the number of nodes in the tree
    // Space: O(h) where h is the height of the tree
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;       
    }
private:
    vector<int> dfs(TreeNode* root){
        if(!root) return {1, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        bool check = left[0] == 1 && right[0] == 1 && (abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1], right[1]);

        return {check ? 1 : 0, height};
    }
};