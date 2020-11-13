/*
 * link => https://leetcode.com/problems/maximum-subarray/
 * first sol time complexity O(n^2) space O(1)
 * second sol time complexity O(n) space O(1)
*/
class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        int sum = INT_MIN;
        for(int i =0; i < nums.size(); i++) {
            int subSum = 0;
            for(int j = i; j < nums.size(); j++ ) {
                subSum+=nums[j];
                sum = max(sum,subSum);
            }
        }
        return sum;
    }
    // Kadanes algorithm
    int maxSubArray2(vector<int>& nums) {
        int meh = 0, msf = INT_MIN; // maximum ending here and maximum so far
        for(int i=0; i < nums.size(); i++) {
            meh = max(meh+nums[i], nums[i]);
            msf = max(meh, msf);
        }
        return msf;
    }
};

