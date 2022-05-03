class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        for(int i=0;i<s.length();i++) {
            char now = s[i];
            if(now == '#') {
                if(!s1.empty()) s1.pop();
            } else s1.push(now);
        }
        
        for(int i=0;i<t.length();i++) {
            char now = t[i];
            if(now == '#') {
                if(!s2.empty()) s2.pop();
            } else s2.push(now);
        }
        
        if(s1.size() != s2.size()) return false;
        while(!s1.empty()) {
            char sNow = s1.top();
            char tNow = s2.top();
            s1.pop(), s2.pop();
            if(sNow != tNow) return false;
        }
        
        return true;
    }
};
