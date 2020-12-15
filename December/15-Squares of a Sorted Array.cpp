class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++) ans.push_back(nums[i]);
        for(int i = 0;i<ans.size();i++) ans[i] *=ans[i];
        sort(ans.begin(),ans.end());
        return ans;
    }
};
