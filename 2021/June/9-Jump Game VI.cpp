class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[100005] = {0, };
        dp[0] = nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({dp[0], 0});
        for(int i=1;i<nums.size();i++){
            while(!pq.empty()){
                int val = pq.top().first, idx = pq.top().second;
                if(idx < i - k) pq.pop();
                else {
                    dp[i] = nums[i] + val;
                    pq.push({dp[i], i});
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
