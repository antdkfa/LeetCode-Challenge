class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> arraySumCount;
        int n = nums.size();
        int i;
        int sum =0;
        arraySumCount[0]=1;
        int ans =0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(arraySumCount.find(sum-k)!=arraySumCount.end()) ans += arraySumCount[sum-k];
            arraySumCount[sum]++;
        }
        return ans;
    }
};
