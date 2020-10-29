/*
 * link => https://leetcode.com/problems/single-number/
 * first approach time,space complexity O(n)
 *  second approach time O(n), space O(1)
 */

class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        map<int,int> freq;
        for(int i=0; i<nums.size(); i++) {
           freq.insert({nums[i], freq[nums[i]]++});
        }
        for(auto i:freq) {
            if (i.second == 1)
                return i.first;
        }
        return -1;
    }

    int singleNumber2(vector<int>& nums) {
        int x = 0;
        for(auto i:nums) {
            x^=i;
        }
        return x;
    }
};



