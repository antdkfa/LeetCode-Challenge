/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let ans = true;
    
    for(let i=0;i<9;i++) {
        let visited = Array.from(Array(10), () => 0);
        for(let j=0;j<9;j++){
            if(board[i][j] === '.') continue;
            visited[board[i][j]]++;
        }
        
        for(let i=1;i<=9;i++) {
            if(visited[i] > 1) ans = false;
        }
    }
    
    for(let i=0;i<9;i++) {
        let visited = Array.from(Array(10), () => 0);
        for(let j=0;j<9;j++) {
            if(board[j][i] === '.') continue;
            visited[board[j][i]]++;
        }
        
        for(let i=1;i<=9;i++) {
            if(visited[i] > 1) ans = false;
        }
    }
    
    for(let i=0;i<9;i+=3) {
        for(let j=0;j<9;j+=3) {
            let visited = Array.from(Array(10), () => 0);
            for(let k=i;k<i+3;k++) {
                for(let q=j;q<j+3;q++){
                    if(board[k][q] == '.') continue;
                    visited[board[k][q]]++;
                }
            }
            
            for(let i=1;i<=9;i++) {
                if(visited[i] > 1) ans = false;
            }
        }
    }
    
    return ans;
};
