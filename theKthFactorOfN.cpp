/*
 * https://leetcode.com/problems/the-kth-factor-of-n/
 * time complexity O(n), space complexity O(1).
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        int p = 0;
        for(int i=1; i <= n; i++){
            if(n%i == 0) {
                if(++p == k) return i;
            }
        }
        return -1;
    }
};
