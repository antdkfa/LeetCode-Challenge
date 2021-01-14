class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        set<pair<int,int>>s;
        int ans=1e9;
        for(int i=nums.size()-1,sum=0;i>=0;i--){
            sum+=nums[i];
            s.insert({sum,-i});
        }
        s.insert({0,-nums.size()});
        auto it=s.lower_bound({x,-1e9});
        if(it!=s.end()&&(*it).first==x) ans=nums.size()+(*it).second;
        for(int i=0,sum=0;i<nums.size();i++){
            sum+=nums[i];
            auto it=s.lower_bound({x-sum,-1e9});
            if(it != s.end()&&(*it).first==x-sum) {
                int idx = -(*it).second;
                if(i<idx && ans>i+1+nums.size()-idx) ans=i+1+nums.size()-idx;
            }
        }
        return ans== 1e9 ? -1 : ans;
    }
};
