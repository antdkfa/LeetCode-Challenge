class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;
    void dfs(vector<int>& candidates, int target, int depth, int sum, vector<int> now){
        if(sum == target){
            ans.push_back(now);
            return;
        }
        for(int i = depth;i<candidates.size();i++){
            if(sum + candidates[i] > target) continue;
            else{
                now.push_back(candidates[i]);
                dfs(candidates,target, i, sum + candidates[i], now);
                now.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target, 0, 0, now);
        return ans;
    }
};
