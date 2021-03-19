class Solution {
public:
    
    int visited[1005] = {0, };
    vector<vector<int>> v;
    void dfs(int now) {
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            if(!visited[next]){
                visited[next]=1;
                dfs(next);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        v.resize(1005);
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                v[i].push_back(rooms[i][j]);
            }
        }
        visited[0]=1;
        dfs(0);
        for(int i=0;i<rooms.size();i++)if(!visited[i]) return false;
        
        return true;
    }
};
