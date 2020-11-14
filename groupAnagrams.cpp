/*
  An anagram of a string is another string that contains same characters,
  only the order of characters can be different.
  problem link ==> https://leetcode.com/problems/group-anagrams/
  useful link ==> https://www.youtube.com/watch?v=0I6IL3TnIZs&list=PLEJXowNB4kPzM42NGnS_9ok5c3iVIx551&index=3
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& s) {
        unordered_map<string,vector<string>> groups;
        for(int i=0;i<s.size();i++){
            string beforeSort = s[i];
            sort(s[i].begin(),s[i].end());
            groups[s[i]].push_back(beforeSort);
        }

        vector<vector<string> > result;

        for(auto itr=groups.begin();itr!=groups.end();++itr)
            result.push_back(itr->second);

        return result;

    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        map<string,vector<string>>m;
        for(int i = 0; i < strs.size(); i++) {
            int count[26] = {0};
            for(int j=0; j < strs[i].length(); j++) count[strs[i][j]-'a']++;
            string s = "";
            for (int i = 0; i < 26; i++) {
                s+="#";
                s+=count[i];
            }
            m[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};
