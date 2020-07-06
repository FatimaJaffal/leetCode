/*
  Complexity O(n/2) space O(1)
  link ==> https://leetcode.com/problems/reverse-string/
*/
class Solution {
public:

    void reverseString(vector<char>& s) {
       int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
    }
};
