class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> m;
        int l=0,r=0,ans=0;
        while(r < nums.size()) {
            m[nums[r]]++;
            if(m[nums[r]] > k) {
                while(nums[l] != nums[r]) {
                    m[nums[l++]]--;
                }
                l++;
                m[nums[r]]--;
            }
            ans = max(ans, r - l + 1); 
            r++;
        }

        return ans;
    }
};
