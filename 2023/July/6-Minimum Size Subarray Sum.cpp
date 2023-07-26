class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0, e = 0, n = nums.size(), sum = 0, ans = 1e9;
        while(s<n && e<n) {
            if(target <= sum + nums[e]) {
                ans = min(ans, e - s + 1);
                sum -= nums[s];
                s++;
            } else sum += nums[e++];
            if(e < s) e = s;
        }

        return ans == 1e9 ? 0: ans;
    }
};
