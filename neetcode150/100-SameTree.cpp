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
      // Recursive approach to compare two binary trees for structural and value equality.
      // Time: O(n) where n is the number of nodes in the smaller tree
      // Space: O(h) where h is the height of the smaller tree
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(p && q && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else{
            return false;
        }
    }
};