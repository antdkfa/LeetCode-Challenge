class Solution {
public:
    vector<vector<int>> v;
    priority_queue<int, vector<int>, greater<int>> pqIdx;
    priority_queue<char,vector<char>, greater<char>> pqChar;
    int visited[100005];
    
    void dfs(string &s, int now) {
        visited[now] = 1;
        pqIdx.push(now);
        pqChar.push(s[now]);
        for(int i=0;i<v[now].size();i++) {
            int next = v[now][i];
            if(!visited[next]) {
                dfs(s, next);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        v.resize(s.length()+1);
    
        for(int i=0;i<pairs.size();i++) {
            v[pairs[i][0]].push_back(pairs[i][1]);
            v[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0;i<s.length();i++) {
            if(!visited[i]) {
                dfs(s, i);
            }
            while(!pqIdx.empty()) {
                int idx = pqIdx.top();
                char c = pqChar.top();
                pqIdx.pop();
                pqChar.pop();
                s[idx] = c;
            }
        }
        
        return s;
    }
};
