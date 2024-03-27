class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, mul = 1, ans = 0;
        while(r < nums.size() && l < nums.size()) {
            if(mul * nums[r] < k) {
                mul *= nums[r++];
                ans += r - l;
            } else {
                mul /= nums[l++];
            }
            if(r < l) {
                r = l;
            }
        }
        return ans;
    }
};
