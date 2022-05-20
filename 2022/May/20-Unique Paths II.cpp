class Solution {
public:
    int fr[2] = {1,0},fc[2] = {0,1}, dp[105][105], n, m;
    
    int dfs(int r,int c, vector<vector<int>>& obstacleGrid) {
        int &ret = dp[r][c];
        if(ret) return ret;
        if(r == n - 1 && c == m - 1) {
            ret = 1;
            return ret;
        }
        for(int i=0;i<2;i++) {
            int nr = r + fr[i], nc = c +fc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || obstacleGrid[nr][nc]) continue;
            ret += dfs(nr,nc,obstacleGrid);
        }
        return ret;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1]) return 0;
        dfs(0,0,obstacleGrid);
        return dp[0][0];
    }
};
