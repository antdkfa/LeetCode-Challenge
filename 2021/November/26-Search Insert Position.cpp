class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target) {
                ans = mid;
                break;
            } else if(nums[mid] < target) {
                ans = mid + 1;
                s = mid + 1;
            } else e = mid - 1;
        }
        
        return ans;
    }
};
