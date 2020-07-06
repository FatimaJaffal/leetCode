/*
  An anagram of a string is another string that contains same characters,
  only the order of characters can be different.
  problem link ==> https://leetcode.com/problems/group-anagrams/
  useful link ==> https://www.youtube.com/watch?v=0I6IL3TnIZs&list=PLEJXowNB4kPzM42NGnS_9ok5c3iVIx551&index=3
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
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
};
