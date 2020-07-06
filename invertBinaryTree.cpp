/*
  Complexity O(n)
  link ==> https://leetcode.com/problems/invert-binary-tree/
*/

// using recursion
class Solution {
public:
    void invertTreeHelper(TreeNode* root) {
        if(!root) return;
        TreeNode* tempLeft = root->left;
        root->left = root->right;
        root->right = tempLeft;
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
       invertTreeHelper(root);
       return root;
    }
};

//using queue
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
       if(!root) return root;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           TreeNode* current = q.front();
           q.pop();
           TreeNode* temp = current->left;
           current->left = current->right;
           current->right = temp;
           if (current->left) q.push(current->left);
           if (current->right) q.push(current->right);
       }
        return root;


    }
};
