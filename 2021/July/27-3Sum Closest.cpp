class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = 1e9, dif = 1e9;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++){
                int s = j + 1, e = nums.size() - 1;
                while(s <= e) {
                    int mid = (s + e) / 2;
                    if(nums[i] + nums[j] + nums[mid] > target) {
                        e = mid - 1;
                    } else {
                        s = mid + 1;
                    }
                    if(abs(nums[i] + nums[j] + nums[mid] - target) < dif) {
                        dif = abs(nums[i] + nums[j] + nums[mid] - target);
                        ans = nums[i] + nums[j] + nums[mid];
                    }
                }
            }
        }
        return ans;
    }
};
