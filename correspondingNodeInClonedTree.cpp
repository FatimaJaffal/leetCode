/* Time complexity O(n)
 * Space complexity O(H) ==> height of tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void inOrder(TreeNode* original,TreeNode* root, TreeNode* target) {
        if(!root || !original) return;
        inOrder(original->left, root->left, target);
        if(original == target) {
            ans = root;
            return;
        }
        inOrder(original->right, root->right, target);   
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inOrder(original, cloned,target);
        return ans;
    }
};
