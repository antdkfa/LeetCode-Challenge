class Solution {
public:
    
    vector<int> ans;
    int uf[1005];
    
    void find(int a, vector<int>& nums) {
        ans.push_back(nums[a]);
        if(uf[a] == a) return;
        else find(uf[a], nums);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int dp[1005] = { 0, }, mxSize = 0, mxLastIdx = 0;
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            dp[i] = 1;
            uf[i] = i;
            int mxVal = 1;
            int mxIdx = i;
            for(int j=0;j<i;j++) {
                if(!(nums[i] % nums[j])) {
                    if(mxVal < dp[j] + 1) {
                        mxVal = dp[j] + 1;
                        mxIdx = j;
                    }
                }
            }
            
            dp[i] = mxVal;
            uf[i] = mxIdx;
            
            if(mxSize < mxVal) {
                mxSize = mxVal;
                mxLastIdx = i;
            }
        }
        
        find(mxLastIdx, nums);
        return ans;
    }
};
