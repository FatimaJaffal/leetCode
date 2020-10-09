/*
 * link ==> https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * time complexity => O(logn) , space complexity O(1)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* p = root;
        TreeNode* t = root;
        while(t) {
            p = t;
            if (val > t->val)
                t = t->right;
            else
                t = t->left;
        }
        TreeNode* n = new TreeNode(val);
        if (p->val > val) 
            p->left = n;
        else
            p->right = n;
        return root;       
    }
};
