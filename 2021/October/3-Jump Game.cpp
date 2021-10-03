class Solution {
public:
    bool canJump(vector<int>& nums) {
        int visited[10005] = { 0, };
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int i=now + nums[now];i>=now+1;i--) {
                if(i >= nums.size() - 1) {
                    visited[nums.size() - 1] = 1;
                    break;
                }
                if(visited[i]) break;
                else {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        return visited[nums.size() - 1];
    }
};
