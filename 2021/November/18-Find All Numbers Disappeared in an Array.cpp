class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int appeared[100005] = {0,};
        for(int i=0;i<nums.size();i++) {
            appeared[nums[i]] = 1;
        }
        
        vector<int> ans;
        for(int i=1;i<=nums.size();i++) {
            if(!appeared[i]) ans.push_back(i);
        }
        
        return ans;
    }
};
