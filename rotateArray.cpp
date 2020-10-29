/*
 * sol1 ==> time O(n*k) space O(1) 
 * sol2 ==> time O(n) space O(n)
 * sol3 ==> time O(n) space O(1)
 */

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        k%=v.size();
        int temp,prev;
        for(int i=0; i < k;i++) {
            prev = v[v.size()-1];
            for(int j=0; j < v.size(); j++) {
                temp = v[j];
                v[j] = prev;
                prev = temp;
            }
        }
    }
};

// sol2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i=0; i< nums.size();i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }
        for(int i=0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};

//sol3
class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;   
        }
    }
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
