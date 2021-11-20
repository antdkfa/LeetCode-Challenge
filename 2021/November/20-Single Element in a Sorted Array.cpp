class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int ans;
        for(int i=0;i<nums.size();i+=2) {
            if(nums[i] != nums[i+1]) {
                ans = nums[i];
                break;
            }
        }
        
        return ans;
    } 
};
