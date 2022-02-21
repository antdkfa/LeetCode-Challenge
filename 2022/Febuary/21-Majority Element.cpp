class Solution {
public:
    unordered_map<int,int> um;
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            um[nums[i]]++;
            if(um[nums[i]] > nums.size() / 2) ans = nums[i];
        }
        return ans;
    }
};
