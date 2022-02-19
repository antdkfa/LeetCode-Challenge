class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;
    
    void rec(vector<int>& nums, int idx) {
        ans.push_back(now);
        for(int i=idx;i<nums.size();i++) {
            now.push_back(nums[i]);
            rec(nums, i + 1);
            now.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        rec(nums, 0);
        return ans;
    }
};
