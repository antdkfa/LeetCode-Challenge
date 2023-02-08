class Solution {
public:

    int dp[10005];
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 0;
        while(!q.empty()) {
            int now = q.front().first, depth = q.front().second;
            q.pop();
            int next = now + nums[now];
            if(next >= nums.size() - 1) {
                ans = depth + 1;
                break;
            }
            for(int i=next;i>=0;i--) {
                if(!dp[i]) {
                    dp[i] = 1;
                    q.push({i, depth + 1});
                } else break;
            }
        }

        return ans;
    }
};
