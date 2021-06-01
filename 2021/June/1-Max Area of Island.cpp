class Solution {
public:
    int fr[4] = {-1,1,0,0},fc[4]={0,0,-1,1}, visited[55][55] = {0, }, ans = 0, n, m, depth = 0;
    void go(int r,int c, vector<vector<int>> grid){
        for(int i=0;i<4;i++){
            int nr=r+fr[i],nc=c+fc[i];
            if(nr<0 || nr>=n || nc<0 || nc >=m || visited[nr][nc] || !grid[nr][nc]) continue;
            visited[nr][nc] = 1;
            depth++;
            go(nr,nc,grid);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]) depth = 1, visited[i][j] = 1, go(i,j,grid);
                ans = max(ans, depth);
            }
        }
        return ans;
    }
};
