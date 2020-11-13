class Solution {
public:
    // extra space time,space complexity O(n)
    void moveZeroes1(vector<int>& nums) {
        vector<int> extra;
        int count = 0;
        for(int i =0;i<nums.size();i++) {
            if(nums[i]) extra.push_back(nums[i]);
            else count++;
        }
        nums = extra;
        while(count--) nums.push_back(0);
    }


    // time O(n) , space O(1)
    void moveZeroes2(vector<int>& nums) {
        int l = 0, r = 0;
        while(r < nums.size()) {
            if(nums[r]) {
                swap(nums[r], nums[l]);
                r++;
                l++;
            } else r++;
        }
    }
};
