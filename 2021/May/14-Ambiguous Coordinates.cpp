class Solution {
public:
    vector<string>pre[15], post[15];
    
    void set(int l, int r, vector<string> &now, string s){
        int zcnt = 0;
        for(int i=l;i<=r;i++) if(s[i] == '0') zcnt++;
        if(zcnt == r - l + 1){
            if(l == r) now.push_back("0");
            return;
        }
        if(s[l] == '0' && s[r] == '0') return;
        string tmp = ""; 
        if(s[l] == '0'){
            for(int i=l;i<=r;i++) {
                if(i == l + 1) tmp += '.';
                tmp += s[i];
            }
            now.push_back(tmp);
        }
        else {
            for(int i=l;i<=r;i++) tmp += s[i];
            now.push_back(tmp);
            if(s[r] == '0') return;
            
            tmp = "";
            for(int i=l+1;i<=r;i++){
                tmp = "";
                for(int j=l;j<=r;j++){
                    if(i == j) tmp += '.';
                    tmp +=s[j];
                }
                now.push_back(tmp);
            }   
        }
    }
    
    vector<string> ambiguousCoordinates(string s) {
        for(int i=1;i<s.length() -1;i++) set(1,i,pre[i], s);
        for(int i=s.length()-2;i>=1;i--) set(i,s.length()-2,post[i], s);
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<pre[i].size();j++){
                for(int k=0;k<post[i+1].size();k++){
                    ans.push_back("(" + pre[i][j] + ", " + post[i+1][k] + ")");
                }
            }
        }
        return ans;
    }
};
