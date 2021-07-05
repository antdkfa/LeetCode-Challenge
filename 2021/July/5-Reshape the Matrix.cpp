class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(m*n != r*c) return mat;
        
        vector<vector<int>> ans;
        ans.resize(r);
        int ar = 0, ac = 0;
        for(int i=0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                ans[ar].push_back(mat[i][j]);
                ac++;
                if(ac == c) {
                    ac = 0;
                    ar++;
                }
            }
        }
        return ans;
    }
};
