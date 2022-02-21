class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<string> now;
    
    bool isPalindrome() {
        for(int i=0;i<now.size();i++) {
            for(int j=0;j<now[i].length()/2;j++) {
                if(now[i][j] != now[i][now[i].length() - j - 1]) return false;
            }
        }
        return true;
    }
    
    void rec(int idx, string s) {
        if(idx == n) {
            if(isPalindrome()) ans.push_back(now);
            return;
        }
        string tmp = "";
        tmp +=s[idx];
        now.push_back(tmp);
        rec(idx+1, s);
        now.pop_back();
        now[now.size()-1] += s[idx];
        rec(idx+1, s);
    }
    
    vector<vector<string>> partition(string s) {
        string tmp = "";
        tmp +=s[0];
        now.push_back(tmp);
        n = s.length();
        rec(1,s);
        return ans;
    }
};
