class Solution {
public:
    int ans = 0, cnt = 0, fr[4] = {-1,1,0,0}, fc[4] = {0,0,-1,1};

void go(int r, int c,vector<vector<int>>&grid) {
	cnt++;
	grid[r][c] = 0;
	for (int i = 0;i < 4;i++) {
		int nr = r + fr[i], nc = c + fc[i];
		if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || !grid[nr][nc]) continue;
		go(nr, nc, grid);
	}
}
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {   
        for (int i = 0;i < grid.size();i++) {
            for (int j = 0;j < grid[i].size();j++) {
                if (grid[i][j]) {
                    cnt = 0;
                    go(i, j, grid);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
