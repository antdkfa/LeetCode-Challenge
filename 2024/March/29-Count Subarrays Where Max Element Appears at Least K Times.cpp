class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for(int num: nums) {
            mx = max(mx, num);
        }

        long long ans = 0;
        int l = 0, r = 0, cnt = 0;
        while(r < nums.size()) {
            if(nums[r] == mx) cnt++;
            while(cnt >= k) {
                if(nums[l] == mx) cnt--;
                l++;
                ans += nums.size() - r;
            }
            r++;
        }

        return ans;
    }
};
