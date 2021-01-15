class Solution {
public:
    int getMaximumGenerated(int n) {
        int nums[105] = {0,}, ans=0;
        if(!n) return 0;
        nums[1]=1;
        ans = 1;
        for(int i=2;i<=n;i++){
            if(i%2) nums[i]=nums[i/2]+nums[i/2+1];
            else nums[i]=nums[i/2];
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};
