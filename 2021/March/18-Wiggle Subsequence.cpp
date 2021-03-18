class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=0, now=nums[0], dir=0;
        for(int i=1;i<nums.size();i++){
            if(now > nums[i]){
                if(dir == 1) ans++;
                dir = -1;
            }
            else if(now < nums[i]) {
                if(dir == -1) ans++; 
                dir = 1;    
            }
            now = nums[i];
        }
        if(!dir) return 1;
        return ans + 2;
    }
};
