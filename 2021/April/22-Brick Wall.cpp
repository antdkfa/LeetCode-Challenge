class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), ans = 1e9, dp[100005] = { 0, };
        for(int i=0;i<n;i++){
            int now = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                now+=wall[i][j];
                dp[now]++;
            }
        }
        for(int i=0;i<100005;i++){
            ans = min(ans, n - dp[i]);
        }
        return ans;
    }
};
