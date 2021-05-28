class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, visited[10005] = {0, }, s = 0, e = 0, n = nums.size(), sum = 0;
        while(e < n) {
            if(visited[nums[e]]){
                visited[nums[s]] = 0;
                sum -= nums[s];
                s++;
            }
            else {
                visited[nums[e]] = 1;
                sum += nums[e];
                e++;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
