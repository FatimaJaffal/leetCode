/*
 * link ==> https://leetcode.com/problems/symmetric-tree/
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
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        //return isMirror(root, root);  
       queue<TreeNode*> q;
       q.push(root);
       q.push(root);
       while(!q.empty()) {
           TreeNode* temp1 = q.front();
           q.pop();
           TreeNode* temp2 = q.front();
           q.pop();
           if (!temp1 && !temp2) continue;
           if (!temp1 || !temp2) return false;
           if (temp1->val != temp2->val) return false;
           q.push(temp1->left);
           q.push(temp2->right);
           q.push(temp1->right);
           q.push(temp2->left);
       }
        return true;
    }
};
