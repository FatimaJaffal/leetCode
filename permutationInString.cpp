// Complexity O(|s2|*alphabets_size)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> s2Hash(26,0);
       vector<int> s1Hash(26,0);
       int window = s1.size();
       int len = s2.size();
       if(window > len) return false;
       int right = 0 , left = 0;
       while(right < window) {
            s1Hash[s1[right]-'a']++;
            s2Hash[s2[right]-'a']++;
            right++;
        }
        right-=1;
        while(right < len){
            if(s1Hash == s2Hash) return true;
            right+=1;
            if(right != len) s2Hash[s2[right]-'a']++;
            s2Hash[s2[left]-'a']--;
            left+=1;
        }
        return false;
    }
};
