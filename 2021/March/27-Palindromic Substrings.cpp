class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<1005;j++){
                if(i - j < 0 || i + j >= s.length()) break;
                if(s[i-j] == s[i+j]) ans++;
                else break;
            }
        }
        for(int i=0;i<s.length() - 1;i++){
            if(s[i] == s[i+1]) {
                for(int j=0;j<1005;j++){
                    if(i - j < 0 || i + 1 + j >= s.length()) break;
                    if(s[i-j] == s[i+1+j]) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};
