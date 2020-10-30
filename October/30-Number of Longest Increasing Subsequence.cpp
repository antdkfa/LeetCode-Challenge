class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        // cnt[i][len] = number of increasing sequence of length len ending at i  
        vector<vector<int>> cnt(n, vector<int>(n+1, 0));
        for(int i=0; i<n; i++) {
            cnt[i][1] = 1;
        }
        
        int lis = 1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    // add sequences 
                    cnt[i][dp[i]] += cnt[j][dp[j]];
                }
            }
            lis = max(lis, dp[i]);
        }
        
        // finally count all the subsequence of length lis, ending at any index
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += cnt[i][lis];
        }
        return ans;
    }
};
