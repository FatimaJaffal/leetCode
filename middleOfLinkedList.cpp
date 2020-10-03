/* 
 * link => https://leetcode.com/problems/middle-of-the-linked-list/
 * time complexity O(n) space complexity O(1)
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	
     ListNode* middleNodeEasy(ListNode* head) {
        int n = 0;
        ListNode* t = head;
        while (t) {
            n++;
            t = t->next;
        }
        n = n/2;
        int index = 0;
        while (head) {
          if (index == n) return head;
          index++;
          head = head->next;
        }
        return head;
      }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
