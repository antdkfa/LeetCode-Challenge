class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int pre[100005] = {0,}, post[100005] = {0, };
        pre[0] = nums[0], post[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1;i<nums.size();i++) pre[i] = min(pre[i-1], nums[i]);
        for(int i = nums.size() - 2;i>=0;i--) post[i] = max(post[i + 1], nums[i]);
        for(int i = 1;i<nums.size() - 1;i++) {
            if(pre[i-1] < nums[i] && nums[i] < post[i+1]) return true;
        }
        return false;
    }
};
