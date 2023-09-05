class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105][105] = {0, }, mod = 2000000000;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!i || !j) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
