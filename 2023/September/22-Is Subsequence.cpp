class Solution {
public:
    bool isSubsequence(string s, string t) {
      int s1=0, s2=0;
      while(s1 < s.length() && s2 < t.length()) {
        if(s[s1] == t[s2]) s1++,s2++;
        else s2++;
      }

      return s1 == s.length();
    }
};
