class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        set<int> s;
        int dp_pre[10005] = {0, };
        dp_pre[0] = nums[0]; 
        for(int i = 1;i<nums.size();i++){
            dp_pre[i] = min(dp_pre[i-1], nums[i]);
        }
        s.insert(nums[nums.size() - 1]);
        for(int i = nums.size() - 2;i>0;i--){
            int now = nums[i];
            if(now > dp_pre[i - 1]){
                auto it = s.upper_bound(dp_pre[i-1]);
                if(it != s.end() && *it < now) return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
