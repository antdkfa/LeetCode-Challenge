class Solution {
public:
    bool ans = false;
    int visited[10][10], fr[4] = {-1,1,0,0},fc[4]={0,0,-1,1}, n, m;
    
    int isOutside(int r, int c) {
        return (r < 0 || r >= n || c < 0 || c >=m);
    }
    
    void go(int r, int c, string now, vector<vector<char>>& board, string word) {
        if(ans) {
            return;
        }
        if(now == word) {
            ans = true;
            return;
        }
        for(int i=0;i<4;i++) {
            int nr = r + fr[i], nc = c + fc[i];
            if(isOutside(nr,nc) || visited[nr][nc]) continue;
            else {
                if(board[nr][nc] == word[now.length()]) {
                    visited[nr][nc] = 1;
                    go(nr,nc, now + board[nr][nc], board, word);
                    visited[nr][nc] = 0;
                }
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        
        for(int i=0;i<n;i++) {
            if(ans) break;
            for(int j=0;j<m;j++) {
                if(ans) break;
                if(board[i][j] == word[0]) {
                    string head = "";
                    head += board[i][j];
                    visited[i][j] = 1;
                    go(i,j,head,board, word);
                    visited[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};
