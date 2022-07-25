class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1, sIdx = -1,eIdx=-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target) {
                sIdx = mid;
                e = mid-1;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else e = mid - 1;
        }
        
        s=0,e=nums.size()-1;
         while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target) {
                eIdx = mid;
                s = mid + 1;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else e = mid - 1;
        }
        
        vector<int> ans;
        ans.push_back(sIdx);
        ans.push_back(eIdx);
        return ans;
    }
};
