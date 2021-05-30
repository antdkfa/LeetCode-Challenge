class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        typedef pair<int,int> p;
        priority_queue<p> pq;
        int l = 0, r = k - 1;
        for(int i = 0;i<k;i++) pq.push({nums[i], i});
        p now = pq.top();
        ans.push_back(now.first);
        while(1) {
            l++,r++;
            if(r == nums.size()) break;
            pq.push({nums[r],r});
            while(!pq.empty()){
                now = pq.top();
                if(l <= now.second && now.second <= r) {
                    ans.push_back(now.first);
                    break;
                }
                else pq.pop();
            }
        }
        return ans;
    }
};
