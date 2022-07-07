class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int dp[105][105] = {0, };
        if(s1.length() + s2.length() != s3.length()) return false;
        for(int i=0;i<=s1.length();i++) {
            for(int j=0;j<=s2.length();j++) {
                if(!i&&!j) dp[i][j] = 1;
                else if(!i) {
                    dp[i][j] =  (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                } else if(!j) {
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                } else {
                    dp[i][j] = ((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
