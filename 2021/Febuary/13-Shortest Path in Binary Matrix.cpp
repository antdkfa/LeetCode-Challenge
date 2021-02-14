class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])return -1;
        int visited[105][105] ={0,}, fr[8]={-1,-1,-1,0,1,1,1,0}, fc[8]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<105;i++)for(int j=0;j<105;j++)visited[i][j]=-1;
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second,depth=visited[r][c];
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+fr[i],nc=c+fc[i],ndepth=depth+1;
                if(nr<0||nr>=grid.size()||nc<0||nc>=grid.size()||visited[nr][nc]!=-1||grid[nr][nc]) continue;
                else{
                    visited[nr][nc]=ndepth;
                    q.push({nr,nc});
                }
            }
        }
        return visited[grid.size()-1][grid.size()-1];
    }
};
