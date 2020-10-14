class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        int ans = 0;
        int dp[105] = {0, };
        dp[0] = nums[0], dp[1] = max(nums[0],nums[1]);
        ans = max(dp[0], dp[1]);
        for(int i = 2;i<nums.size() - 1;i++){
            if(i-1>= 0) dp[i] = max(dp[i-1],dp[i]);
            if(i-2>= 0) dp[i] = max(dp[i-2]+nums[i], dp[i]);
            if(i-3>= 0) dp[i] = max(dp[i-3]+nums[i], dp[i]);
            ans = max(ans, dp[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[1] = nums[1], dp[2] = max(nums[1],nums[2]);
        ans = max(max(ans, dp[1]),dp[2]);
        for(int i = 3;i<nums.size();i++){
            if(i-1>= 0) dp[i] = max(dp[i-1],dp[i]);
            if(i-2>= 0) dp[i] = max(dp[i-2]+nums[i], dp[i]);
            if(i-3>= 0) dp[i] = max(dp[i-3]+nums[i], dp[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
