class Solution {
public:
    int dp[205][205],ans,n,m,fr[4] = {-1,1,0,0},fc[4] = {0,0,-1,1};
    int go(int r,int c,vector<vector<int>>& matrix) {
        int &ret = dp[r][c];
        if(ret) return dp[r][c];
        ret = 1;
        for(int i=0;i<4;i++){
            int nr = r+fr[i],nc = c+fc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || matrix[r][c] >= matrix[nr][nc]) continue;
            else{
                ret = max(ret, go(nr,nc,matrix)+1);
            }
        }
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!dp[i][j])go(i,j,matrix);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);  
            }
        }
        return ans;
    }
};
