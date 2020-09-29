class Solution {
public:
    bool ans = false;
    set<pair<int,int>> s;
    void dfs(string s, vector<string> wordDict, int depth){
        auto it = s.lowerbound({depth, 0});
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0;i<s.length();i++){
            for(int j = 0;j<wordDict.size();j++){
                if(i + wordDict[j].length() - 1 >= n) continue;
                int flag = 0;
                for(int k = 0;k<wordDict[j].length();k++){
                    if(s[i + k] != wordDict[j][k]) flag = 1;
                }
                if(!flag) s.insert({i,i+wordDict[j].length() - 1});
            }
        }
        return ans;
    }
};
