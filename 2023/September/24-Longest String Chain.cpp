class Solution {
public:
    unordered_map<string,int> visited;
    vector<vector<string>> v;
    int ans = 0, start = 0;
    void go(string now, int depth){
        ans = max(ans, depth - start + 1);
        for(int i=0;i<v[depth+1].size();i++){
            string next = v[depth+1][i];
            if(!visited[next]){
                int idx1 = 0, idx2 = 0;
                while(idx1 < now.length() && idx2 < next.length()){
                    if(idx2 - idx1 > 1) break;
                    if(now[idx1] != next[idx2])idx2++;
                    else idx1++, idx2++;
                }
                //되는 경우
                if(idx2 - idx1 <= 1) visited[next] = 1, go(next, depth+1);
            }
        }
    }
    
    int longestStrChain(vector<string>& words) {
        v.resize(20);
        for(int i=0;i<words.size();i++) v[words[i].length()].push_back(words[i]);
        for(int i=1;i<=16;i++) {
            for(int j=0;j<v[i].size();j++){
                start = i;
                if(!visited[v[i][j]]) visited[v[i][j]] = 1, go(v[i][j], i);
            }
        }
        return ans;
    }
};
