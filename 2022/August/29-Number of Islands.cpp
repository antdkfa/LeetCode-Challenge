class Solution {
public:
    int fr[4] = {-1,1,0,0},fc[4]={0,0,-1,1},cnt;
    void dfs(int r, int c,vector<vector<char>>&grid) {
        grid[r][c]='0';
        for(int i=0;i<4;i++) {
            int nr = r+fr[i], nc=c+fc[i];
            if(nr<0||nr>=grid.size()||nc<0||nc>=grid[0].size()||grid[nr][nc]=='0') continue;
            else dfs(nr,nc,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
