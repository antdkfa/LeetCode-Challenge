class Solution {
public:
    int visited[5005];
    map<string,int>m;
    vector<vector<int>>v;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        m[beginWord] = 1;
        int endIdx = 1e9;
        for(int i = 0;i<wordList.size();i++) {
            if(wordList[i] == beginWord) continue;
            m[wordList[i]] = i+2;
            if(wordList[i] == endWord) endIdx = i+2;
        }
        if(endIdx == 1e9) return 0;
        v.resize(wordList.size()+5);
        for(int i = 0;i<wordList.size();i++){
            int dif1 = 0;
            for(int j=0;j<wordList[i].length();j++){
                if(beginWord[j] != wordList[i][j]) dif1++;
            }
            if(dif1 == 1) {
                v[m[beginWord]].push_back(m[wordList[i]]);    
                v[m[wordList[i]]].push_back(m[beginWord]);
            }
        }
        for(int i = 0;i<wordList.size();i++){
            for(int j = i+1;j<wordList.size();j++){
                int dif = 0;
                for(int k=0;k<wordList[i].length();k++){
                    if(wordList[i][k] != wordList[j][k]) dif++;
                }
                if(dif == 1) {
                    v[m[wordList[i]]].push_back(m[wordList[j]]);
                    v[m[wordList[j]]].push_back(m[wordList[i]]);
                }
            }
        }
        queue<pair<int,int>>q;
        q.push({1,0}),visited[1]=1;
        while(!q.empty()){
            int now = q.front().first, depth = q.front().second;
            if(now == endIdx) return depth + 1;
            q.pop();
            for(int i = 0;i<v[now].size();i++){
                int next=v[now][i];
                if(!visited[next]){
                    visited[next] = 1;
                    q.push({next,depth+1});
                }
            }
        }
        return 0;
    }
};
