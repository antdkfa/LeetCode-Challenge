class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> ans;
        for(int i = 0; i<s.length();i++){
            if(i + 9 >= s.length()) break;
            string now = "";
            for(int j = i;j<i+10;j++){
                now += s[j];
            }
            if(m[now] == 1) ans.push_back(now),m[now] = 2;
            if(!m[now]) m[now] = 1;
        }
        return ans;
    }
};
