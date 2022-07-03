class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int cnt = 0;
        int before = nums[0];
        for(int i=1;i<nums.size() - 1;i++) {
            if(before <= nums[i] && nums[i] <= nums[i+1]) cnt++;
            else if(nums[i] <= before && nums[i+1] <= nums[i]) cnt++;
            else before = nums[i];
        }
        if(before == nums[nums.size() - 1]) cnt++;
        return nums.size() - cnt;
    }
};
