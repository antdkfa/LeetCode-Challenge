class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[3] = {0}, Maxprices = -prices[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 1; j++) dp[j] = dp[j+1];
            dp[2] = max(dp[1], prices[i] + Maxprices);
            Maxprices = max(Maxprices, -prices[i] + dp[0]);
        }
        return dp[2];
    }
};
