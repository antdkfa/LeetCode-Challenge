class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int used[30] ={};
        for(char m: magazine) {
            used[m-'a']++;
        }
        for(char r: ransomNote) {
            used[r-'a']--;
            if(used[r-'a']<0) return false;
        }
        return true;
    }
};
