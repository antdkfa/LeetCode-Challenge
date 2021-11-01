/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    const fr = [-1,1,0,0], fc = [0,0,-1,1], visited = Array.from({length: 205}, ()=>Array.from({length:205}, ()=>0));
    const n = board.length, m = board[0].length;
    
    const visit=(r,c)=>{
        for(let i=0;i<4;i++) {
            let nr = r+fr[i], nc = c+fc[i];
            if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]||board[nr][nc]==='X') continue;
            visited[nr][nc]=1;
            visit(nr,nc);
        }
    }
    
    const capture=(r,c)=>{
        for(let i=0;i<4;i++) {
            let nr=r+fr[i],nc=c+fc[i];
            if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]||board[nr][nc]==='X') continue;
            visited[nr][nc]=1;
            board[nr][nc] = 'X';
            capture(nr,nc);
        }
    }
    
    for(let i=0;i<n;i++) { 
        for(let j=0;j<m;j++) {
            if(!i || !j || i===n-1 || j ===m-1) {
                if(!visited[i][j] && board[i][j] === 'O') {
                    visited[i][j]=1;
                    visit(i,j);
                }
            } 
        }
    }
    
    for(let i=1;i<n-1;i++) {
        for(let j=1;j<m-1;j++) {
            if(!visited[i][j] && board[i][j] === 'O') {
                visited[i][j]=1;
                board[i][j]='X';
                capture(i,j);
            }
        }
    }
    
    return board;
};
