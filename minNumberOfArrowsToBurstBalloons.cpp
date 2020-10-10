/*
 * link => https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * time complexity O(nlongn), space complexity O(1) 
 */

bool interval(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (!points.size()) return 0;
        sort(points.begin(), points.end(), interval);
        int counter = 1;
        int ref = points[0][1];
        for(int i=1; i < points.size(); i++) {
            if (points[i][0] > points[i-1][1] || points[i][0] > ref) {
                counter++;
                ref = points[i][1];
            }
        }
        return counter;
    }
};
