class Solution {
public:
    bool isAnagram(string s, string t) {
        int used[30] = {0, };
        if(s.length()!=t.length())return false;
        for(int i=0;i<s.length();i++){
            used[s[i]-'a']++;
            used[t[i]-'a']--;
        }
        for(int i=0;i<30;i++){
            if(used[i] != 0) return false;
        }
        return true;
    }
};
