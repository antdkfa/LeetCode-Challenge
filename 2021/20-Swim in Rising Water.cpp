class Solution {
public:
    int fr[4] = {-1,1,0,0},fc[4] = {0,0,-1,1}, visited[55][55], N;
    
    int dfs(int r,int c,int mid, vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        visited[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+fr[i], nc = c+fc[i];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || grid[nr][nc] > mid) continue;
                else {
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return visited[N-1][N-1];
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int mn = grid[0][0], mx = grid[0][0], ans = -1;
         for(int i=0;i<N;i++){
             for(int j=0;j<N;j++){
                 mn = min(mn, grid[i][j]);
                 mx = max(mx, grid[i][j]);
             }
         }
        mn = max(grid[0][0], mn);
        while(mn <= mx) {
            memset(visited,0,sizeof(visited));
            int mid = (mn + mx) / 2;
            int now = dfs(0,0,mid,grid);
            if(!now) mn = mid + 1;
            else {
                ans = mid;
                mx = mid - 1;
            }
        }
        return ans;
    }
};
