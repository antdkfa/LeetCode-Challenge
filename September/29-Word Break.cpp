class Solution {
public:
    int visited[1005] = {0,};
    bool ans = false;
    void dfs(string s, vector<string> wordDict, int depth){
        if(depth == s.length()) { ans = true; return; }
        for(int i = 0; i < wordDict.size(); i++){
            if(depth + wordDict[i].length() - 1 >= s.length() || visited[depth + wordDict[i].length() - 1]) continue;
            else{
                int flag = 0;
                for(int j = 0; j < wordDict[i].length(); j++){
                    if(s[depth+j] != wordDict[i][j]) {flag = 1; break;}
                }
                if(!flag) visited[depth + wordDict[i].length() - 1] = 1, dfs(s, wordDict,depth+wordDict[i].length());
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dfs(s,wordDict,0);
        return ans;
    }
};
