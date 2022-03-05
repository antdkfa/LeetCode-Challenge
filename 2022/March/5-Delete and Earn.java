class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] cnt = new int[10005];
        for(int i=0;i<nums.length;i++) {
            cnt[nums[i]]++;
        }
        
        int[] dp = new int[10005];
        dp[1] = cnt[1];
        for(int i=2;i<10005;i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + cnt[i] * i);
        }
        return dp[10004];
    }
}
