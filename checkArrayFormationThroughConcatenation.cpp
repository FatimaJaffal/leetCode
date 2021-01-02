/*
 * Time complexity O(n*m) ==> size of arr, size of pieces
 * Space complexity O(n)
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int founded = 0;
        for(int i =0; i<arr.size(); i++) {
            for(vector<int>p:pieces) {
                if(p[0] == arr[i]) {
                    vector<int> part;
                    if((i + p.size()) > arr.size()) return false;
                    part.insert(part.end(), arr.begin() + i, arr.begin() + i + p.size());
                    if(part != p) {
                        return false;
                    }
                    i+=p.size() - 1;
                    founded += p.size();
                }
            }
        }
        return founded == arr.size();
    }
};
