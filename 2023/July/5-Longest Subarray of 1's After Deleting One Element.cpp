class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        int cnt=0;
        for(int i=0;i<nums.size();i++) {
            if(!nums[i]) {
                v.push_back(cnt);
                cnt=0;
                v.push_back(cnt);
            } else cnt++;
        }
        v.push_back(cnt);
        
        int ans = max(0, v[0]-1);
        for(int i=0;i<v.size();i++) {
            int l=0,r=0;
            if(i-1>=0) l=v[i-1];
            if(i+1<v.size()) r=v[i+1];
            ans = max(ans, l+r);
        }
        return ans;
    }
};
