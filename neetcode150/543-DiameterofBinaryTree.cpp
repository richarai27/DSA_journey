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
  // Calculate tree height via DFS while updating the maximum path length through each node
  // Time complexity: O(n) where n is the number of nodes in the binary tree
  // Space complexity: O(h) where h is the height of the binary tree (due to the recursive call stack)
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* root,int& result){
        if(!root) return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);
        return 1 + max(left, right);

    }
};