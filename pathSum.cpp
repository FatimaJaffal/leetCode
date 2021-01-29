/*
 * link ==> https://leetcode.com/problems/path-sum/
 * time and space complexity O(n).
*/

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
    bool preOrder(TreeNode* root, int targetSum, int sum) {
      if(!root) return false;
      sum+= root->val;
      if(!root->right && !root->left && targetSum == sum) {
        return true;
      }
      return preOrder(root->left, targetSum, sum) || preOrder(root->right, targetSum, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preOrder(root, targetSum, 0);
    }
};
