class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> tmp;
        s+=' ';
        int ans = 0, cnt = 1;
        for(int i=0;i<s.length() - 1;i++){
            if(s[i] != s[i+1]){
                tmp.push_back(cnt);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        for(int i=0;i<tmp.size() - 1;i++){
            ans += min(tmp[i], tmp[i+1]);
        }
        return ans;
    }
};
