/*
 * link ==> https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 * Time complexity O(n), Space complexity O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int all = 0;
    void getMax(Node* root, int count) {
      if(!root) return;
      for(int i = 0; i < root->children.size(); i++) {
        getMax(root->children[i], count + 1);
      }
      all = max(all, count);
    }
    int maxDepth(Node* root) {
      getMax(root, 1);
      return all; 
    }
};
