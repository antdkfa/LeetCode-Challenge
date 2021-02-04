class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(!m[nums[i]]) v.push_back(nums[i]);
            m[nums[i]]++;
        }
        for(int i=0;i<v.size();i++){
            if(m[v[i]]&&m[v[i]+1])ans=max(ans,m[v[i]]+m[v[i]+1]);
        }
        return ans;
    }
};
