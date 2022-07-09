class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            while(1) {
                int val = pq.top().first;
                int idx = pq.top().second;
                if(i - idx > k) {
                    pq.pop();
                    continue;
                }
                pq.push({val+nums[i], i});
                if(i == nums.size() - 1) ans = val + nums[i];
                break;
            }
        }
        
        return ans;
    }
};
