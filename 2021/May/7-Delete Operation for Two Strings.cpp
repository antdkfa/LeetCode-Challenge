class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1, word2 = " " + word2;
        int dp[505][505] = {0, }, n = word1.length(), m = word2.length();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i||!j) continue;
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m + n - 2 * dp[n][m];
    }
};
