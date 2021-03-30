class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int dp[5005], ans = 1;
        for(int i=0;i<5005;i++) dp[i] = 1;
        sort(envelopes.begin(),envelopes.end());
        for(int i=1;i<envelopes.size();i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j]+1);
            }    
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
