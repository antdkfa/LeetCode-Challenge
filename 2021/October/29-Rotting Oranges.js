/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const visited = Array.from({length: 15}, () => Array.from({length: 15}, () => -1));
    
    const queue = [];
    grid.forEach((row, i) => {
        row.forEach((orange, j) => {
            if(orange === 2) {
                visited[i][j] = 0;
                queue.push([i,j,0]);
            }
        }) 
    })
    
    const fr = [-1,1,0,0], fc = [0,0,-1,1];
    while(queue.length) {
        const arr = queue.shift();
        let r = arr[0], c = arr[1], cnt = arr[2];
        for(let i=0;i<4;i++) {
            let nr = r + fr[i], nc = c + fc[i];
            if(nr < 0 || nc < 0 || nr >= grid.length || nc >= grid[0].length || grid[nr][nc] != 1) continue;
            grid[nr][nc] = 2;
            visited[nr][nc] = cnt + 1;
            queue.push([nr,nc,cnt+1]);
        }
    }
    
    let ans = 0;
    for(let i=0;i<grid.length;i++) {
        for(let j=0;j<grid[0].length;j++) {
            if(visited[i][j] === -1 && grid[i][j] === 1) {
                return -1;
            }
            if(visited[i][j] != -1) ans = Math.max(ans, visited[i][j]);
        }
    }
    return ans;
};
