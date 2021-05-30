class Solution {
public:
    int sum, visited[205], dp[20005];
    
    void dfs(int now, vector<int>nums){
        for(int i = 0;i<nums.size();i++){
            if(!visited[i]){
                int next = now + nums[i];
                if(next > sum / 2 || dp[next]) continue;
                visited[i] = 1;
                dp[next] = 1;
                dfs(next, nums);
                visited[i] = 0;
            }
        }
    }
    
    bool canPartition(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
           sum+=nums[i]; 
        }
        if(sum % 2) return false;
        dfs(0, nums);
        return dp[sum/2] ? true : false;
    }
};
