class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int dp[10005][30] = {0, };
        int used[30] = {0, };
        for(int i=0;i<s1.length();i++) {
            used[s1[i] - 'a']++;
        }
        
        dp[0][s2[0] - 'a'] = 1;
        for(int i = 1; i < s2.length(); i++) {
            for(int j=0;j<=26;j++) {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][s2[i] - 'a']++;
        }
        
        for(int i = s1.length() - 1;i<s2.length();i++) {
            bool flag = true;
            for(int j=0;j<26;j++) {
                if (used[j] != dp[i][j] - ((i >= s1.length()) ? dp[i - s1.length()][j]: 0)) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        
        return false;
    }
};
