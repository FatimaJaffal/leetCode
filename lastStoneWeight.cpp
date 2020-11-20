// link ==> https://leetcode.com/problems/last-stone-weight/
// time complexity O(nlongn), space complexity O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int s:stones) 
            q.push(s);
        while(q.size() > 1) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(y-x != 0) q.push(y-x);
        }
        if(!q.empty()) return q.top();
        return 0;
    }
};
