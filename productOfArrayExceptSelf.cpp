/*
 * https://leetcode.com/problems/product-of-array-except-self/
 * sol1 ==> time complexity O(n), space complexity O(1)
 * sol2 ==> time complexity O(n), space complexity O(n)
 * sol3 ==> time complexity O(n), space complexity O(n)
*/


class Solution {
public:

   	
   vector<int> productExceptSelf1(vector<int>& nums) {
        int all = 1;
        int allWithoutZero = 1;
        int zeroCount = 0;
        for(int i:nums) {
             all*=i;
            if(i == 0) zeroCount++;
            if(i != 0) allWithoutZero*=i;
        }
           
        for(int i =0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(zeroCount == 1) nums[i] = allWithoutZero;
                 else nums[i] = 0;   
            }  else {
                if(all == 0) nums[i] = 0;
                else nums[i] = all/nums[i];
            }
        }
        return nums;
    }

     vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n);
        vector<int>r(n);
        
        l[0] = 1;
        
        for(int i=1; i < n; i++) {
            l[i] = l[i-1] * nums[i-1];
        }
        
        r[n-1] = 1;
        for(int i= n - 2; i >= 0; i--) {
            r[i] = r[i+1] * nums[i+1];
        }
        
        for(int i=0; i < n; i++) {
            nums[i] = l[i] * r[i];
        }
        
        return nums;
        
    }

    vector<int> productExceptSelf3(vector<int>& nums) {
        int n = nums.size();
        vector<int>a(n);
        
        a[0] = 1;
        
        for(int i=1; i < n; i++) {
            a[i] = a[i-1] * nums[i-1];
        }
        
        int R = 1;
        for(int i= n - 1; i >= 0; i--) {
            a[i] = a[i] * R;
            R*=nums[i];
        }
        
        return a;
        
    }
};
