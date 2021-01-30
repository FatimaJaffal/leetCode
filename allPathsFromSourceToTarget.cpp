/* link => https://leetcode.com/problems/all-paths-from-source-to-target/
 * time and space complexity O(n^2). 
*/
class Solution {
public:
    vector<vector<int>> all;
    void dfs(vector<vector<int>> graph, int current, int target, vector<int> path) {
        path.push_back(current);
        if (current == target) {
            all.push_back(path);
            return;
        }
        for (int i: graph[current]) 
         dfs(graph, i, target, path);    
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1, vector<int>{});
        return all;
    }
};
