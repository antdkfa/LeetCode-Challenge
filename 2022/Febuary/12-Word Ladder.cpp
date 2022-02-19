class Solution {
public:
    unordered_map<string,int> m;
    vector<vector<int>> v;
    int visited[5005] = {0, };
    
    int dif(string a, string b) {
        int cnt = 0;
        for(int i=0;i<a.length();i++) {
            if(a[i] != b[i]) cnt++;
            if(cnt>1) break;
        }
        return cnt;
    }
    
    void bfs(string beginWord, vector<string> &wordList) {
        queue<int> q;
        visited[0] = 1;
        for(int i=0;i<wordList.size();i++) {
            int cnt = dif(beginWord, wordList[i]);
            if(cnt <= 1) {
                q.push(m[wordList[i]]);
                visited[m[wordList[i]]] = 2;
            }
        }
        
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int i=0;i<v[now].size();i++) {
                int next = v[now][i];
                if(!visited[next]) {
                    visited[next] = visited[now] + 1;
                    q.push(next);
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        v.resize(wordList.size() + 5);
        int idx = 0;
        m[beginWord] = idx++;
        for(int i=0;i<wordList.size();i++) m[wordList[i]] = idx++;
        if(!m[endWord]) return 0;
        
        for(int i=0;i<wordList.size();i++) {
            for(int j=i+1;j<wordList.size();j++) {
                int cnt = dif(wordList[i], wordList[j]);
                if(cnt <= 1) {
                    v[m[wordList[i]]].push_back(m[wordList[j]]);
                    v[m[wordList[j]]].push_back(m[wordList[i]]);
                } 
            }
        }
        
        bfs(beginWord, wordList);
        return visited[m[endWord]];
    }
};
