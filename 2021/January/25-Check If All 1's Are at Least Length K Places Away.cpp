class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                if(idx==1e9) idx=i;
                else {
                    int now=i-idx;
                    idx=i;
                    if(now<=k) return false;
                }
            }
        }
        return true;
    }
};
