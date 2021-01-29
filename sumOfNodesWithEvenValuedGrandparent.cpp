/*
 * link ==> https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    int sum = 0;
    void dfs(TreeNode* root, TreeNode* parent, TreeNode* grand) {
      if (!root) return;
      if (grand && grand->val %  2 == 0) {
        sum+= root->val;
      }
      dfs(root->left, root, parent);
      dfs(root->right, root, parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, nullptr, nullptr);
        return sum;
    }
};
