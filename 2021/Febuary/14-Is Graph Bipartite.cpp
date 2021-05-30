class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        int visited[105]={0,};
        v.resize(105);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                v[i].push_back(graph[i][j]);
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            if(!visited[i]) {
                q.push({i,1});
                visited[i]=1;
            }
            while(!q.empty()){
                int now = q.front().first, color=q.front().second;
                q.pop();
                for(int i=0;i<v[now].size();i++){
                    int next=v[now][i], ncolor;
                    if(color==1)ncolor=2;
                    else ncolor=1;
                    if(!visited[next]) {
                        visited[next]=ncolor;
                        q.push({next,ncolor});
                    }
                    else if(visited[next]==color) return false;
                }
            }
        }
        return true;
    }
};
