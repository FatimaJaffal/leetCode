class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t;
        for(int i =0; i < S.length(); i++) {
            if(S[i] != '#') {
                s.push(S[i]);
            } else {
                if(!s.empty()) s.pop();
             }
        }
        for(int i =0; i < T.length(); i++) {
            if(T[i] != '#') {
                t.push(T[i]);
            } else {
                if(!t.empty()) t.pop();
             }
        }
        
        return s == t;
        
    }

    bool backspaceCompare2(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(S[i] == '#') {
                    skipS++;
                    i--;
                }
                else if(skipS > 0) {
                    skipS--;
                    i--;
                } else break;
            }

            while(j >= 0) {
                if(T[j] == '#') {
                    skipT++;
                    j--;
                }
                else if(skipT > 0) {
                    skipT--;
                    j--;
                } else break;
            }

            if(i >= 0 && j >= 0 && S[i] != T[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;

    }
};
