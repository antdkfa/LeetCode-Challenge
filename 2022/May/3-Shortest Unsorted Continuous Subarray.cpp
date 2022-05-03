class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums;
        for(int i=0;i<nums.size();i++) sortedNums.push_back(nums[i]);
        sort(sortedNums.begin(), sortedNums.end());
        
        int s = 0, n = sortedNums.size();
        while(s < n) {
            if(nums[s] != sortedNums[s]) break;
            s++;
        }
        
        int e = n - 1;
        while(e >= 0) {
            if(nums[e] != sortedNums[e]) break;
            e--;
        }
        
        if(e < s) return 0;
        return e - s + 1;
    }
};
