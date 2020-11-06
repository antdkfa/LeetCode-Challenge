class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = 10e6, size = nums.size(), ans;
        while(s<=e){
            int mid = (s + e) / 2, now = 0;
            for(int i = 0;i<size;i++){
                now += nums[i] / mid + (nums[i] % mid ? 1 : 0);
            }
            if(now <= threshold){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
