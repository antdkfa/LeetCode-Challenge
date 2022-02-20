class Solution {
public:
    char findTheDifference(string s, string t) {
        int letter[30] = {0,};
        
        char ans = 'a';
        for(int i=0;i<s.length();i++) {
            letter[s[i] - 'a']++;
        }
        
        for(int i=0;i<t.length();i++) {
            letter[t[i] - 'a']--;
            if(letter[t[i] - 'a'] == -1) ans = t[i];
        }
        return ans;
    }
};
