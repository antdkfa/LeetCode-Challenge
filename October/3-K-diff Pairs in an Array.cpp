class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<pair<int,int>,int> visited;
        map<int,int> num;
        int ans;
        for(int i = 0;i<nums.size();i++){
            num[nums[i]]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(num[nums[i] + k]){
                int a = nums[i], b = nums[i] + k;
                if(visited[{a,b}]) continue;
                else{
                    if(a == b && num[a] == 1) continue;
                    else{
                        visited[{a,b}] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
