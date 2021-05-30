class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> v;
        v.resize(n);
        for(int i = 0;i<n;i++) v[i].resize(n);
        int fr[4] = {0,1,0,-1}, fc[4] = {1,0,-1,0}, visited[25][25] = {0, }, depth, opt;
        typedef pair<int,int>p;
        queue<p>q;
        q.push({0,0}); 
        v[0][0] = 1;
        visited[0][0] = 1, depth = 1, opt = 0;
        while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if(depth == n * n) break;
            int nr = r + fr[opt], nc = c + fc[opt];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]){
                opt = (opt+1) % 4;
                q.push({r,c});
            }
            else{
                visited[nr][nc] = 1;
                depth++;
                v[nr][nc] = depth;
                q.push({nr,nc});
            }
        }
        return v;
    }
};
