class Solution {
public:
    int n, visited[10];
    vector<vector<int>>ans;
    vector<int> v;
    map<string,int>m;
    void go(int depth, vector<int>nums){
        if(depth == n){
            string now = "";
            for(int i = 0;i<v.size();i++){
                now+=to_string(v[i]);
            }
            if(!m[now]){
                m[now] = 1;
                ans.push_back(v);
            }
        }
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                visited[i] = 1;
                v.push_back(nums[i]);
                go(depth+1,nums);
                visited[i] = 0;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        go(0, nums);
        return ans;
    }
};
