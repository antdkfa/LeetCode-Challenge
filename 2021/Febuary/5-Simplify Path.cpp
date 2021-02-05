class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        path+='/';
        string now="";
        deque<string>s;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(now=="") continue;
                else if(now==".") { now=""; }
                else if(now=="..") {
                    if(s.size()) s.pop_back();
                    now=""; 
                }
                else {
                    s.push_back(now);
                    now="";
                }
            }
            else now+=path[i];
        }
        if(s.empty()) return "/";
        while(!s.empty()){
            string tmp = s.front();
            s.pop_front();
            ans+='/';
            ans+=tmp;
        }
        return ans;
    }
};
