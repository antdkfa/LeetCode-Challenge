class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int now = 0, cnt = 1;
        nums.push_back(1e9);
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] == nums[i+1]) cnt++;
            else {
                if(2 <= cnt) {
                    nums[now] = nums[now + 1] = nums[i];
                    now+=2;
                } else {
                    nums[now] = nums[i];
                    now++;
                }
                cnt = 1;
            }
        }
        return now;
    }
};
