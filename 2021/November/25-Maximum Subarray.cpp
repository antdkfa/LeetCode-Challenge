class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sum = max(sum, nums[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};
