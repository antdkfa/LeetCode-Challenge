class Solution {
public:
    bool ans = true;
    unordered_map<string,int>m;
    
    void go(int depth, int k, string now) {
        if(depth == k) {
            if(!m[now]) ans = false;
            return;
        }
        if(ans == false) return;
        go(depth + 1, k, now + '1');
        go(depth + 1, k, now + '0');
    }
    
    bool hasAllCodes(string s, int k) {
        for(int i=0;i<s.length();i++){
            string tmp = "";
            if(i+k > s.length()) break;
            for(int j=i;j<i+k;j++) {
                tmp += s[j];
            }
            m[tmp]=1;
        }   
        go(0,k,"");
        return ans;
    }
};
