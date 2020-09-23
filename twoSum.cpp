/*
    Time Complexity: O(n), Space Complexity O(n)
    Link ==> https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0; i < nums.size(); i++) {
            if (m.count(nums[i])) 
                return vector<int>{i, m[nums[i]]};
            else
                m.insert({target - nums[i], i});
        }
        return vector<int>{};
    }
};
