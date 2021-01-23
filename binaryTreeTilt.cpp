/* link ==> https://leetcode.com/problems/binary-tree-tilt/
 * time and space complexity O(n).
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
    int ans = 0;
    int postOrder(TreeNode* root) {
      if (!root) return 0;
      int left = postOrder(root->left);
      int right = postOrder(root->right);
      ans+= abs(left - right);
      return root->val + left + right;
    }
    int findTilt(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
