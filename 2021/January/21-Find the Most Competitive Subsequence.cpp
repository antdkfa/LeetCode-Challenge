class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        int idx1=-1;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size()-k;i++)pq.push({-nums[i],-i});
        for(int i=nums.size()-k;i<nums.size();i++){
            while(!pq.empty()){
                int j=-pq.top().second;
                if(j<idx1) pq.pop();
                else break;
            }
            pq.push({-nums[i],-i});
            int now=-pq.top().first, idx=-pq.top().second;
            pq.pop();
            idx1=idx,ans.push_back(now);
        }
        return ans;
    }
};
