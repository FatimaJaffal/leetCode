/*
 * link ==> https://leetcode.com/problems/binary-search/
 * time complexity O(logn), space complexity O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while(low < high) {
            int mid = low + ((high - low)/2);
            if (nums[mid] == target) return mid;
            if ( nums[mid] > target ) high--;
            else low++;
        }
        return -1;
    }
};
