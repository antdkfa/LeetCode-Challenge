class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            ans = min(sum, ans);
        }
        
        if(ans >=0) return 1;
        else return abs(ans) + 1;
    }
};
