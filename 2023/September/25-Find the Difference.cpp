class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[30] = {0, };
        for(int i=0;i<s.length();i++) {
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++) {
            cnt[t[i]-'a']--;
            if(cnt[t[i]-'a'] == -1) {
                return t[i];
            }
        }

        return 'a';
    }
};
