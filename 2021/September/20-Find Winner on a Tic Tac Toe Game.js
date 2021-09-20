/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let board = [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]];
    let winner;
    moves.forEach((move, idx) => {
        board[move[0]][move[1]] = idx % 2;
        const result = getWinner();
        if(result) {
            winner = result;
        }
    })
    
    if(winner) return winner;
    
    board.forEach(row => {
        row.forEach(item => {
            if(item === -1) {
                winner = "Pending";
            }
        })
    })
    
    if(winner) return winner;
    
    function getWinner() {
        for(let i=0;i<3;i++) {
            if(board[i][0] != -1) {
                let flag = true;
                for(let j=0;j<3;j++) {
                    if(board[i][j] != board[i][0]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    if(!board[i][0]) return "A";
                    else return "B";
                }
            }
        }   
        
        for(let i=0;i<3;i++) {
            if(board[0][i] != -1) {
                let flag = true;
                for(let j=0;j<3;j++) {
                    if(board[j][i] != board[0][i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    if(!board[0][i]) return "A";
                    else return "B";
                }
            }
        }
        
        if(board[0][0] != -1 && board[0][0] === board[1][1] && board[1][1] === board[2][2]) {
            if(!board[0][0]) return "A";
            else return "B";
        }
        
        if(board[0][2] != -1 && board[0][2] === board[1][1] && board[1][1] === board[2][0]) {
            if(!board[0][2]) return "A";
            else return "B";
        }
    }
    
    return "Draw";
};
