class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }
        
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            int now = nums[i], pair = k - nums[i];
            if(now == pair) {
                if(2 <= m[now]) {
                    m[now] -=2;
                    ans++;
                }              
            } else {
                if(m[now] && m[pair]) {
                    m[now]--;
                    m[pair]--;
                    ans++;
                }
            }
        }
        return ans;
    }
};
