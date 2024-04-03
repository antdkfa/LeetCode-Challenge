class Solution {
public:
    bool visited[10][10], ans = false;
    int fr[4] = {-1,1,0,0}, fc[4] = {0,0,-1,1}, mxR, mxC;
    void dfs(int r, int c, string now, vector<vector<char>>&board,string word) {
        if(word.substr(0,now.size()) != now) {
            return;
        }
        if(now == word) {
            ans = true;
            return;
        }

        for(int i=0;i<4;i++) {
            int nr = r+fr[i], nc = c + fc[i];
            if(nr < 0 || nr >= mxR || nc < 0 || nc >= mxC || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            dfs(nr,nc,now+board[nr][nc],board,word);
            visited[nr][nc] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        mxR = board.size(), mxC = board[0].size();
        for(int i=0;i<mxR;i++) {
            for(int j=0;j<mxC;j++) {
                visited[i][j]=true;
                string tmp = "";
                tmp+=board[i][j];
                dfs(i,j,tmp,board,word);
                visited[i][j]=false;
            }
        }

        return ans;
    }
};
