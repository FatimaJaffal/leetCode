/* link ==> https://leetcode.com/problems/balanced-binary-tree/
 * first solution time and space complexity O(n^2).
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
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        int diff = abs(lh - rh);
        return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};



// second solution
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
    bool helper(TreeNode* root, int* height = 0) {
        int lh = 0, rh = 0;
        if (!root) {
            *height = 0;
            return true;
        }
        bool l = helper(root->left, &lh);
        bool r = helper(root->right, &rh);
        *height = max(lh, rh) + 1;
        int diff = abs(lh - rh);
        return diff <= 1 && l && r;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return helper(root, &height);
    }
};
