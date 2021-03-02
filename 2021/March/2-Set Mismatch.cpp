class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int visited[10005] = { 0, }, a, b;
        vector<int>ans;
        for(int i=0;i<nums.size();i++) visited[nums[i]]++;
        for(int i=1;i<=nums.size();i++){
            if(!visited[i]) a=i;
            if(visited[i]==2) b=i;
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};
