class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string now = "";
        for(int i=0;i<s.length()/2;i++) {
            now += s[i];
            if(s.length() % now.length() == 0) {
                string tmp = "";
                for(int i=0;;i++) {
                    tmp += now;
                    if(tmp.length() == s.length()) break;
                }
                if(tmp == s) return true;
            }
        }
        
        return false;
    }
};
