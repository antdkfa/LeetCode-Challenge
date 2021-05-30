class Solution {
public:
    vector<vector<string>> ans;
    int len = 0;
    string s;
    
    bool is_palin(vector<string> v){
        for(int i = 0;i<v.size();i++){
            for(int j = 0, k = v[i].length() - 1;j<v[i].length()/2;j++, k--){
                if(v[i][j] != v[i][k]) return false;
            }
        }
        return true;
    }
    
    void dfs(vector<string> v, int depth, string s){
        if(depth == s.length()) {
            if(is_palin(v))ans.push_back(v);
            return;
        }
        else{
            string tmp = "";
            tmp += s[depth];
            v.push_back(tmp);
            dfs(v, depth+1,s);
            v.pop_back();
            v[v.size() - 1] += s[depth];
            dfs(v, depth + 1, s);
        }
    }
    
    vector<vector<string>> partition(string s) {
        len = s.length();
        vector<string>v;
        string tmp = "";
        tmp += s[0];
        v.push_back(tmp);
        dfs(v,1,s);
        return ans;
    }
};
