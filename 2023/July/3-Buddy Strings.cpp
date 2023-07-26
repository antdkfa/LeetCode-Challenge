class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        int dif=0,first=-1,second=-1, cnt[30]={};
        for(int i=0;i<s.length();i++) {
            if(s[i] != goal[i]) {
                dif++;
                if(first==-1) first=i;
                else second=i;
            }
            cnt[s[i]-'a']++;
        }
        if(dif == 2) {
            if(s[first] == goal[second] && s[second] == goal[first]) return true;
        } else if(!dif) {
            for(int i=0;i<26;i++) {
                if(2<=cnt[i]) return true;
            }
        } return false;
    }
};
