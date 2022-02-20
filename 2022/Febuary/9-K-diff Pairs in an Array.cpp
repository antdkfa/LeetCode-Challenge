class Solution {
public:
    unordered_map<int,int> um;
    int findPairs(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) {
            if(um[nums[i]]) um[nums[i]]++;
            else um[nums[i]] = 1;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(i+1 != nums.size() && nums[i]==nums[i+1]) continue;
            int now = nums[i];
            int next = k + now;
            if(next < now) break;
            if(now == next) {
                if(um[now] >= 2) ans++;
            }
            else if(um[next]) ans++;
        }
        return ans;
    }
};
