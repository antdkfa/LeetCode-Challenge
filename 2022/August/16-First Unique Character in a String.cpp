class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int>> v;
        v.resize(30);
        for(int i=0;i<s.length();i++) {
            int now = s[i] - 'a';
            v[now].push_back(i);
        }
        
        int ans = 1e9;
        for(int i=0;i<30;i++) {
            if(v[i].size() == 1) {
                ans = min(ans, v[i][0]);
            }
        }
        
        if(ans == 1e9) return -1;
        return ans;
    }
};
