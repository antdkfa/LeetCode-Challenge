class Solution {
public:
     vector<vector<string>> ans;
    int fr[3] = {1,1,1}, fc[3] = {-1,0,1}, visited[15][15];
    
    void fillColor(int r, int c, int from, int to, int n){
        for(int i=0;i<3;i++){
            int nr = r + fr[i], nc = c + fc[i];
            while(nr < n && nc < n && nr >= 0 && nc >= 0){       
                if(visited[nr][nc] == from) visited[nr][nc] = to;         
                nr += fr[i], nc += fc[i];
            }
        }
    }
    
    void go(int r,int c, int n, int depth) {
        if(r == n-1){
            vector<string> tmp;
            for(int i=0;i<n;i++){
                string now = "";
                for(int j=0;j<n;j++){
                    if(visited[i][j] == -1) now += 'Q';
                    else now += '.';
                }
                tmp.push_back(now);
            }
            ans.push_back(tmp);
            return;
        }
        
        fillColor(r,c,0, depth, n);
        
        for(int i=0;i<n;i++){
            if(!visited[r+1][i]){
                visited[r+1][i] = -1;
                go(r+1,i,n, depth + 1);
                visited[r+1][i] = 0;
            }
        }
        
        fillColor(r,c,depth, 0, n);
        
    }
    int totalNQueens(int n) {
        for(int i=0;i<n;i++){
            visited[0][i] = -1;
            go(0,i,n, 1);
            visited[0][i] = 0;
        }
        return ans.size();
    }
};
