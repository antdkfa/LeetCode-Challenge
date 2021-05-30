class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(!nums.size() || !k) return;
        vector<int> v;
        for(int i = (nums.size() - k) ;i< (2 * nums.size() - k) ;i++){
            v.push_back(nums[i % nums.size()]);
        }
        nums = v;
    }
};
