class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int fr[] = {-1,1,0,0}, fc[] = {0,0,-1,1}, ans = 0;
       for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[i].size();j++) {
            if(grid[i][j]) {
                for(int k=0;k<4;k++) {
                    int nr =  i + fr[k], nc = j + fc[k];
                    if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[i].size() || !grid[nr][nc]) ans++;
                }
            }
        }
       } 

       return ans;
    }
};
