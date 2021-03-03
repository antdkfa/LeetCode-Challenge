class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int visited[10005] = {0,};
        for(int i=0;i<nums.size();i++)visited[nums[i]]=1;
        for(int i=0;i<=nums.size();i++) {
            if(!visited[i]) return i;
        }
        return 0;
    }
};
