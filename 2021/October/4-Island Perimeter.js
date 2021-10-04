/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    const n = grid.length, m = grid[0].length, fr = [-1,1,0,0],fc=[0,0,1,-1];
    let ans = 0;
    
    for(let i=0;i<n;i++) {
        for(let j=0;j<m;j++) {
            if(grid[i][j]) {
                for(let k=0;k<4;k++) {
                    let nr = i+fr[k], nc = j + fc[k];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || !grid[nr][nc]) ans++;
                }
            }
        }
    }
    
    return ans;
};
