class Solution {
public:
    unordered_map<int,int> um;
    int findMaxLength(vector<int>& nums) {
        int sum = 0, ans = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if(!sum) ans = i + 1;
            else if(um[sum]) {
                ans = max(ans, i + 1 - um[sum]);
            } else {
                um[sum] = i + 1;
            }
        }
        return ans;
    }
};
