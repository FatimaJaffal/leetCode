/* 
 * link ==> https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 *
 * time and space O(n).
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
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if(left > right) return NULL;
        int mid = left+(right-left)/2;
        int midVal = nums[mid];
        TreeNode* n = new TreeNode(midVal);
        n->left = buildTree(nums, left, mid - 1);
        n->right = buildTree(nums, mid + 1, right);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {    
        return buildTree(nums, 0, nums.size() - 1);
    }
};
