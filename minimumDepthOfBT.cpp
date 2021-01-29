/*
 * link ==> https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int preOrder(TreeNode* root) {
      if (!root) return 0;
      if (root->right && !root->left) return 1 + preOrder(root->right);
      if (root->left && !root->right) return 1 + preOrder(root->left);
      return 1 + min(preOrder(root->left), preOrder(root->right));
    }
    int minDepth(TreeNode* root) {
      return preOrder(root);
    }
};
