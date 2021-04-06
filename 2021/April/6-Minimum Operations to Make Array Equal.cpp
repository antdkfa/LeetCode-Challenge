class Solution {
public:
    int minOperations(int n) {
       int dp[10005] = { 0, };
        for(int i = 1;i<=n;i++) dp[i] = dp[i-1] + i/2;
        return dp[n];
    }
};
