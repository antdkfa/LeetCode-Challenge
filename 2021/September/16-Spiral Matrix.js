/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let fr = [0,1,0,-1], fc = [1,0,-1,0], r = 0, c = -1, dir = 0;
    const visited = Array.from({length: matrix.length}, () => Array.from({length: matrix[0].length}, () => 0));
    let ans = [];
    for(let i=0;i<matrix.length;i++){
        for(let j=0;j<matrix[i].length;j++) {
            let nr = r + fr[dir], nc = c + fc[dir];
            if(nr < 0 || nr >= matrix.length || nc < 0 || nc >= matrix[i].length || visited[nr][nc]) {
                dir = (dir + 1) % 4;
                j--;
            } else {
                visited[nr][nc] = 1;
                ans.push(matrix[nr][nc]);
                r = nr, c = nc;
            }
        }
    }
    
    return ans;
};
