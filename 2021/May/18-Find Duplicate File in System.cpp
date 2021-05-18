class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,string> m;
        for(int i=0;i<paths.size();i++){
            int idx = 0;
            string dir = "", name = "", content = "";
            for(idx=0;idx<paths[i].length();idx++){
                if(paths[i][idx] == ' ') break;
                dir += paths[i][idx];
            }
            bool isContent = false;
            for(;idx<paths[i].length();idx++){
                if(paths[i][idx] == ' ') continue;
                else if(paths[i][idx] == ')'){
                    m[content] += dir + "/" + name + " ";
                    name = "", content = "", isContent = false;
                }
                else if(paths[i][idx] == '('){
                    isContent = true;
                }
                else {
                    if(isContent) content += paths[i][idx];
                    else name += paths[i][idx];
                }
            }
        }
        vector<vector<string>> ans;
        for(auto it = m.begin();it != m.end();it++){
            string now = it->second;
            vector<string> v;
            string tmp = "";
            for(int i=0;i<now.length();i++){
                if(now[i] == ' ') v.push_back(tmp), tmp = ""; 
                else tmp +=now[i];
            }
            if(v.size() > 1) ans.push_back(v);
        }
        return ans;
    }
};
