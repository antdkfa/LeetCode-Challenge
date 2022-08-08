class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, dp[2505] = { 0, };
        dp[0]=1;
        
        for(int i=1;i<nums.size();i++){
            int now = 1;
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) {
                    now = max(now, dp[j] + 1);
                }
            }    
            dp[i] = now; 
            ans = max(ans, now);
        }
        
        return ans;
    }
};
