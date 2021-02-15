class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]) cnt++;
                else break;
            }
            q.push({-cnt,-i});
        }
        for(int i=0;i<k;i++){
            ans.push_back(-q.top().second);
            q.pop();
        }
        return ans;
    }
};
