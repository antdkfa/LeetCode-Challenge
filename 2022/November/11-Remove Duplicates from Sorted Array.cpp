class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        int k = 0;
        for(int i=0;i<nums.size();i++) {
            if(m[nums[i]]) continue;
            else m[nums[i]] = 1, nums[k++] = nums[i];
        }
        
        return k;
    }
};
