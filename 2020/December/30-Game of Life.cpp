class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(), fr[8] = {-1,-1,-1,0,0,1,1,1}, fc[8] ={
            -1,0,1,-1,1,-1,0,1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int one = 0;
                for(int k = 0;k<8;k++){
                    int nr = i + fr[k], nc = j + fc[k];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(board[nr][nc] == 1 || board[nr][nc] == -3 || board[nr][nc] == -4) one++;
                }
                if(!board[i][j]){
                    if(one == 3) board[i][j] = -2;
                    else board[i][j] = -1;
                }
                else{
                    if(one == 2 || one == 3) board[i][j] = -4;
                    else board[i][j] = -3;
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == -1 || board[i][j] == -3) board[i][j] = 0;
                else board[i][j] = 1;
            }
        }
    }
};
