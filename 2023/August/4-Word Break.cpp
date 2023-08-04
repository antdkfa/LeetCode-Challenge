class Solution {
public:
    bool ans, visited[305];

    void solve(string now, string s, vector<string>& wordDict) {
        if(ans || visited[now.length()]) return;
        if(now == s) {
            ans = true;
            return;
        }
        if(s.substr(0, now.length()) != now) {
            return;
        }
        visited[now.length()] = 1;
        for(int i=0;i<wordDict.size();i++) {
            solve(now + wordDict[i], s, wordDict);
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        solve("", s, wordDict);
        return ans;
    }
};
