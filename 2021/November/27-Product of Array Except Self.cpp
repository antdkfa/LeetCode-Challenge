class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> pre, post;
        
        ans.resize(nums.size());
        pre.resize(nums.size());
        post.resize(nums.size());
        
        pre[0] = nums[0];
        post[nums.size() - 1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++) {
            pre[i] = pre[i-1] * nums[i];
        }
        
        for(int i=nums.size() - 2;i>=0;i--) {
            post[i] = post[i+1] * nums[i];
        }
        
        for(int i=1;i<nums.size()-1;i++) {
            ans[i] = pre[i-1] * post[i+1];
        }
        ans[0] = post[1], ans[nums.size() - 1] = pre[nums.size() - 2];
        return ans;
    }
};
